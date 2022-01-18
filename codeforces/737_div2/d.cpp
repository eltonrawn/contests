#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 600010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


class Data  {
public:
    int lazy, val, pos;
    Data()  {lazy = -1;val = 0;pos = 0;}
};
 
Data tree[4 * SZ];

void updval(int node, int le_ran, int ri_ran, int lazy, int pos)    {
    tree[node].val = lazy;
    tree[node].pos = pos;
    tree[node].lazy = lazy;
    ///tree[node].lazy += lazy;
}
 
void update(int node, int le_ran, int ri_ran)    {
    ///tree[node].lazy += 1;
    if(tree[node].lazy != -1) {
        if(le_ran != ri_ran)    {
            int mid = (le_ran + ri_ran) / 2;
            updval(node * 2, le_ran, mid, tree[node].lazy, tree[node].pos);
            updval((node * 2) + 1, mid + 1, ri_ran, tree[node].lazy, tree[node].pos);
        }
        tree[node].lazy = -1;
    }
}
 
void update_range(int node, int le_ran, int ri_ran, int le, int ri, int val, int pos)  {///ran = range
    ///cout << "node : " << node << "\n";
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        updval(node, le_ran, ri_ran, val, pos);
        ///update(node, le_ran, ri_ran);
        return;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) / 2;
    update_range(node * 2, le_ran, mid, le, ri, val, pos);
    update_range((node * 2) + 1, mid + 1, ri_ran, le, ri, val, pos);
    // tree[node].val = max(tree[node * 2].val, tree[(node * 2) + 1].val);
    if(tree[node * 2].val > tree[node * 2 + 1].val) {
        tree[node].val = tree[node * 2].val;
        tree[node].pos = tree[node * 2].pos;
    }
    else {
        tree[node].val = tree[node * 2 + 1].val;
        tree[node].pos = tree[node * 2 + 1].pos;
    }
}
 
 
PII query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return {0, 0};
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        ///cout << node << " : " << tree[node].val << "\n";
        return {tree[node].val, tree[node].pos};
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) / 2;

    PII v1 = query(node * 2, le_ran, mid, le, ri);
    PII v2 = query((node * 2) + 1, mid + 1, ri_ran, le, ri);
    if(v1.first > v2.first) return v1;
    return v2;
}


int n, m;
pair<int, pair<int, int>> ara[SZ];
set<int> st;
map<int, int> mp;
int par[SZ];
map<int, int> ache;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ara[i] = {a, {b, c}};
        st.insert(b); st.insert(c);
    }

    int cnt = 1;
    for(int val: st) {
        mp[val] = cnt++;
    }

    sort(ara + 1, ara + 1 + m);
    int ans = 0;
    int anspos = 0;

    for(int i = 1; i <= m; i++) {
        int j = i;
        while((j <= m) && (ara[j].first == ara[i].first)) {
            j++;
        }
        j--;

        int mx = 0;
        int mxpos = 0;

        for(int k = i; k <= j; k++) {
            PII yoyo = query(1, 1, cnt, mp[ara[k].second.first], mp[ara[k].second.second]);
            if(yoyo.first > mx) {
                mx = yoyo.first;
                mxpos = yoyo.second;
                // cout << "mxpos : " << mxpos << endl;
            }
            // cout << ara[k].second.first << " " << ara[k].second.second << " : " << yoyo.first << " " << yoyo.second << endl;
        }

        for(int k = i; k <= j; k++) {
            update_range(1, 1, cnt, mp[ara[k].second.first], mp[ara[k].second.second], mx + 1, ara[i].first);
        }

        par[ara[i].first] = mxpos;
        // cout << "par : " << ara[i].first << " " << mxpos << endl;
        if(mx + 1 > ans) {
            ans = mx + 1;
            anspos = ara[i].first;
        }

        // cout << ara[i].first << " : " << mx + 1 << endl;

        i = j;
    }
    
    int u = anspos;
    while(u > 0) {
        // cout << "u : " << u << endl;
        ache[u] = 1;
        u = par[u];
    }

    cout << n - ans << endl;
    for(int i = 1; i <= n; i++) {
        if(!ache[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}
/**
 * tags: segment tree, lazy propogation
*/
