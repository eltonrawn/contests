#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


class Data  {
public:
    LL lazy, val;
    Data()  {lazy = -1; val = 0;}
    void operator = (const Data &d) {
        ///lazy = d.lazy;
        val = d.val;
    }
    Data operator + (const Data &d) {
        Data dd;
        ///dd.lazy = lazy + d.lazy;
        dd.val = val + d.val;
        return dd;
    }
};

class Segtree {
public:
    Data tree[SZ * 4];
    
    void updval(int node, int le_ran, int ri_ran, LL lazy)    {
        tree[node].val = ((ri_ran - le_ran + 1) * lazy);
        tree[node].lazy = lazy;
        ///tree[node].lazy += lazy;
    }
 
    void update(int node, int le_ran, int ri_ran)    {
        ///tree[node].lazy += 1;
        if(tree[node].lazy != -1) {
            if(le_ran != ri_ran)    {
                int mid = (le_ran + ri_ran) / 2;
                updval(node * 2, le_ran, mid, tree[node].lazy);
                updval((node * 2) + 1, mid + 1, ri_ran, tree[node].lazy);
            }
            tree[node].lazy = -1;
        }
    }
    
    void update_range(int node, int le_ran, int ri_ran, int le, int ri, LL val)  {///ran = range
        if((ri_ran < le) || (le_ran > ri))    {///not in range
            return;
        }
        if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
            updval(node, le_ran, ri_ran, val);
            return;
        }
        update(node, le_ran, ri_ran);
    
        int mid = (le_ran + ri_ran) / 2;
        update_range(node * 2, le_ran, mid, le, ri, val);
        update_range((node * 2) + 1, mid + 1, ri_ran, le, ri, val);
        tree[node] = tree[node * 2] + tree[(node * 2) + 1];
    }
    
    
    LL query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
        if((ri_ran < le) || (le_ran > ri))    {///not in range
            return 0;
        }
        if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
            return tree[node].val;
        }
        update(node, le_ran, ri_ran);
    
        int mid = (le_ran + ri_ran) / 2;
        LL ans = 0;
        ans += query(node * 2, le_ran, mid, le, ri);
        ans += query((node * 2) + 1, mid + 1, ri_ran, le, ri);
        return ans;
    }

};


string source, target;
int n, q;
PII ara[SZ];

Segtree seg_zero = Segtree();
Segtree seg_one = Segtree();

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> q;
        cin >> source >> target;
        for(int i = 1; i <= q; i++) {
            cin >> ara[i].first >> ara[i].second;
        }

        for(int i = 0; i < n; i++) {
            if(target[i] == '0') {
                seg_zero.update_range(1, 1, n, i + 1, i + 1, 1);
                seg_one.update_range(1, 1, n, i + 1, i + 1, 0);
            }
            else {
                seg_zero.update_range(1, 1, n, i + 1, i + 1, 0);
                seg_one.update_range(1, 1, n, i + 1, i + 1, 1);
            }
        }
        bool chk = 1;

        for(int i = q; i >= 1; i--) {
            int l = ara[i].first, r = ara[i].second;
            // cout << l << " " << r << endl;
            int forced_zero = seg_zero.query(1, 1, n, l, r);
            int forced_one = seg_one.query(1, 1, n, l, r);
            int half = ((r - l) / 2) + 1;

            bool is_zero = 0;
            bool is_one = 0;
            if(forced_one < half) {
                is_zero = 1;
            }
            if(forced_zero < half) {
                is_one = 1;
            }

            if(is_zero && is_one) {
                /// can place anything, clear out forced_zero and forced_one
                seg_zero.update_range(1, 1, n, l, r, 0);
                seg_one.update_range(1, 1, n, l, r, 0);
            }
            else if(is_zero) {
                /// place forced_zero to all, clear out forced_one
                seg_zero.update_range(1, 1, n, l, r, 1);
                seg_one.update_range(1, 1, n, l, r, 0);
            }
            else if(is_one) {
                /// place forced_one to all, clear out forced_zero
                seg_zero.update_range(1, 1, n, l, r, 0);
                seg_one.update_range(1, 1, n, l, r, 1);
            }
            else {
                chk = 0;
                break;
            }
        }
        for(int i = 0; i < n && chk; i++) {
            bool is_zero = seg_zero.query(1, 1, n, i + 1, i + 1);
            bool is_one = seg_one.query(1, 1, n, i + 1, i + 1);
            if(!is_zero && !is_one) {}
            if(is_zero && source[i] == '0') {}
            else if(is_one && source[i] == '1') {}
            else {
                chk = 0; break;
            }
        }
        cout << (chk == 0 ? "NO" : "YES") << endl;
    }
    return 0;
}
/**
*/
