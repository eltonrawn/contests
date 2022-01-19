#include<bits/stdc++.h>

using namespace std;

#define SZ 200010
#define MOD 998244353
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


class Data  {
public:
    LL lazy, val;
    Data()  {lazy = 0;val = 0;}
    // void operator = (const Data &d) {
    //     ///lazy = d.lazy;
    //     val = d.val;
    // }
    // Data operator + (const Data &d) {
    //     Data dd;
    //     ///dd.lazy = lazy + d.lazy;
    //     dd.val = val + d.val;
    //     return dd;
    // }
};
 
Data tree[4 * SZ];
LL ara[SZ], csum[SZ];
 
void updval(int node, int le_ran, int ri_ran, LL lazy)    {
    tree[node].val += lazy;
    tree[node].lazy += lazy;
    ///tree[node].lazy += lazy;
}
 
void update(int node, int le_ran, int ri_ran)    {
    ///tree[node].lazy += 1;
    if(tree[node].lazy != 0) {
        if(le_ran != ri_ran)    {
            int mid = (le_ran + ri_ran) / 2;
            updval(node * 2, le_ran, mid, tree[node].lazy);
            updval((node * 2) + 1, mid + 1, ri_ran, tree[node].lazy);
        }
        tree[node].lazy = 0;
    }
}
 
void update_range(int node, int le_ran, int ri_ran, int le, int ri, LL val)  {///ran = range
    ///cout << "node : " << node << "\n";
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        updval(node, le_ran, ri_ran, val);
        ///update(node, le_ran, ri_ran);
        return;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) / 2;
    update_range(node * 2, le_ran, mid, le, ri, val);
    update_range((node * 2) + 1, mid + 1, ri_ran, le, ri, val);
    tree[node].val = min(tree[node * 2].val,  tree[(node * 2) + 1].val);
}
 
 
LL query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return 0;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        ///cout << node << " : " << tree[node].val << "\n";
        return tree[node].val;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) / 2;
    LL ans = min(query(node * 2, le_ran, mid, le, ri), query((node * 2) + 1, mid + 1, ri_ran, le, ri));
    ///cout << node << " : " << ans << "\n";
    return ans;
}

void clear_tree(int node, int le_ran, int ri_ran)  {///ran = range
    // cout << node << ": " << le_ran << " " << ri_ran << endl;
    // return;
    // if(le_ran > ri_ran)    {
    //     return;
    // }
    if(le_ran == ri_ran) {
        ///cout << node << " : " << tree[node].val << "\n";
        tree[node].val = 0;
        tree[node].lazy = 0;
        return;
    }
    int mid = (le_ran + ri_ran) / 2;
    clear_tree(node * 2, le_ran, mid);
    clear_tree(node * 2 + 1, mid + 1, ri_ran);
    tree[node].val = 0;
    tree[node].lazy = 0;
}

int n;
LL s;


// LL work[SZ];
// void upup(int le, int ri, int val) {
//     for(int i = le; i <= ri; i++) {
//         work[i] += val;
//     }
// }

// int qq(int le, int ri) {
//     int ret = 0;
//     for(int i = le; i <= ri; i++) {
//         if(work[i] < 0) break;
//         ret++;
//     }
//     return ret;
// }

int mxval = 0;
PII ans;
void get_ans(int le, int ri) {
    int lo = le;
    int hi = ri;
    while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(query(1, 1, n, le, mid) < 0) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    if(lo >= le && lo <= ri && query(1, 1, n, le, lo) >= 0) {
        if(lo - le + 1 > mxval) {
            mxval = lo - le + 1;
            ans = {le, lo};
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> s;
        csum[0] = s;

        clear_tree(1, 1, n);
        

        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            csum[i] = csum[i - 1] + ara[i];
            update_range(1, 1, n, i, i, csum[i]);
            // upup(i, i, csum[i]);
        }
        // continue;

        mxval = 0;
        // int ans = qq(1, n);
        get_ans(1, n);

        for(int i = 1; i < n; i++) {
            /// remove i from equation
            // upup(i, n, ara[i] * -1);
            update_range(1, 1, n, i, n, ara[i] * -1);
            // ans = max(ans, qq(i + 1, n));
            get_ans(i + 1, n);
        }
        if(mxval == 0) {
            cout << -1 << endl;
        }
        else {
            cout << ans.first << " " << ans.second << endl;
        }
        
    }
    return 0;
}
/**
tags: segment tree, lazy propogoation
this variant does range addition/substraction and does min range query
*/
