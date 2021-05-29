#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
vector<int> adjl[SZ];
int mx_lev[SZ];

int get_lev(int u, int par, int lev) {
    int mx = lev;
    for(int v: adjl[u]) {
        if(v == par) continue;
        mx = max(mx, get_lev(v, u, lev + 1));
    }
    return mx_lev[u] = mx;
}

vector <int> ansv;
LL ans = 0;
int func(int u, int par, int pending_other, bool one_dir, int pending_one) {
    if(!one_dir) {
        pending_other--;
    }
    else {
        pending_one--;
    }
    // cout << u << " " << pending_k << " " << one_dir << endl;
    
    int exclude = 0;
    for(int v: adjl[u]) {
        if(v == par) continue;
        if(mx_lev[v] == mx_lev[u] && one_dir) {
            exclude = v; break;
        }
    }

    for(int v: adjl[u]) {
        if(v == par) continue;
        if(v == exclude) continue;
        if(pending_other) {
            ans += 2;
            ansv.push_back(v);
            pending_other = func(v, u, pending_other, 0, pending_one);
            ansv.push_back(u);
        }
    }

    if(exclude && pending_one) {
        ans += 1;
        ansv.push_back(exclude);
        func(exclude, u, pending_other, one_dir, pending_one);
    }
        

    return pending_other;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            adjl[i].clear();
        }
        for(int i = 2; i <= n; i++) {
            int par; cin >> par;
            adjl[par].push_back(i);
        }
        get_lev(1, 0, 1);
        // for(int i = 1; i <= n; i++)
        //     cout << i << " : " << mx_lev[i] << endl;
        
        ans = 0;ansv.clear();
        ansv.push_back(1);
        func(1, 0, max(0, k - mx_lev[1]), 1, k - max(0, k - mx_lev[1]));
        
        cout << ans << endl;
        for(int val: ansv)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
/**
*/
