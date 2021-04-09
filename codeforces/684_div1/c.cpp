#include<bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000
 
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
struct Data  {
    LL lazy_sum, sum, mn;
    Data()  {
        lazy_sum = -1; 
        sum = 0;
        mn = 0;
 
    }
};
 
Data tree[4 * MX];
LL ara[MX];
int n, q;
 
void updval(int node, int le_ran, int ri_ran, LL lazy) {
    tree[node].sum = ((ri_ran - le_ran + 1) * lazy);
    tree[node].lazy_sum = lazy;
    tree[node].mn = lazy;
    ///tree[node].lazy += lazy;
}
 
void update(int node, int le_ran, int ri_ran) {
    ///tree[node].lazy += 1;
    if(tree[node].lazy_sum != -1) {
        if(le_ran != ri_ran)    {
            int mid = (le_ran + ri_ran) >> 1;
            updval(node << 1, le_ran, mid, tree[node].lazy_sum);
            updval((node << 1) + 1, mid + 1, ri_ran, tree[node].lazy_sum);
        }
        tree[node].lazy_sum = -1;
    }
}
 
void update_range(int node, int le_ran, int ri_ran, int le, int ri, LL val) {///ran = range
    ///cout << "node : " << node << "\n";
    if((ri_ran < le) || (le_ran > ri)) {///not in range
        return;
    }
    if((le_ran >= le) && (ri_ran <= ri)) {///completely in range
        updval(node, le_ran, ri_ran, val);
        ///update(node, le_ran, ri_ran);
        return;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) >> 1;
    
    update_range(node << 1, le_ran, mid, le, ri, val);
    update_range((node << 1) + 1, mid + 1, ri_ran, le, ri, val);
    
    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    tree[node].mn = min(tree[node << 1].mn, tree[(node << 1) + 1].mn);
}
 
 
LL query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return 0;
    }
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        ///cout << node << " : " << tree[node].val << "\n";
        return tree[node].sum;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) >> 1;
    LL ans = 0;
    ans += query(node << 1, le_ran, mid, le, ri);
    ans += query((node << 1) + 1, mid + 1, ri_ran, le, ri);
    ///cout << node << " : " << ans << "\n";
    return ans;
}
 
 
 
bool is_not_in_range(int le_ran, int ri_ran, int le, int ri) {
    if((ri_ran < le) || (le_ran > ri))    {///not in range
        return 1;
    }
    return 0;
}
 
int query_less_eq_pos_suffix(int node, int le_ran, int ri_ran, int le, int ri, LL val)  {///ran = range
    if(is_not_in_range(le_ran, ri_ran, le, ri)) {
        return -1;
    }
    if(le_ran == ri_ran) {
        return le_ran;
    }
    update(node, le_ran, ri_ran);
 
    int mid = (le_ran + ri_ran) >> 1;
    if(is_not_in_range(le_ran, mid, le, ri)) {
        return query_less_eq_pos_suffix((node << 1) + 1, mid + 1, ri_ran, le, ri, val);
    }
 
    if(tree[node << 1].mn <= val) {
        return query_less_eq_pos_suffix(node << 1, le_ran, mid, le, ri, val);
    }
    else if(tree[(node << 1) + 1].mn <= val) {
        return query_less_eq_pos_suffix((node << 1) + 1, mid + 1, ri_ran, le, ri, val);
    }
    return -1;
}
 
int get_less_eq_pos_suffix(int pos, LL val) {
    return query_less_eq_pos_suffix(1, 1, n, pos, n, val);
}
 
int get_less_eq_pos_prefix(int pos, LL val) {
    return query_less_eq_pos_suffix(1, 1, n, 1, pos, val);
}
 
PLL query_csum_less_pos(int node, int le_ran, int ri_ran, int le, int ri, LL val, LL sum)  {///ran = range
    if(is_not_in_range(le_ran, ri_ran, le, ri)) {
        return {0, sum};
    }
    
    update(node, le_ran, ri_ran);
    int mid = (le_ran + ri_ran) >> 1;
 
    if((le_ran >= le) && (ri_ran <= ri))    {///completely in range
        // cout << "qq " << le_ran << " " << ri_ran << " : " << sum << " " << tree[node].sum << " " << sum + tree[node].sum << endl;
        if(sum + tree[node].sum <= val) {
            return {ri_ran, sum + tree[node].sum};
        }
        if(le_ran == ri_ran) {
            return {0, sum};
        }
        return query_csum_less_pos(node << 1, le_ran, mid, le, ri, val, sum);
    }
    update(node, le_ran, ri_ran);
    
    if(is_not_in_range(le_ran, mid, le, ri)) {
        return query_csum_less_pos((node << 1) + 1, mid + 1, ri_ran, le, ri, val, sum);
    }
 
    PLL d1 = query_csum_less_pos(node << 1, le_ran, mid, le, ri, val, sum);
    if(d1.F != mid) {
        return d1;
    }
 
    PLL d2 = query_csum_less_pos((node << 1) + 1, mid + 1, ri_ran, le, ri, val, d1.S);
    if(d2.F == 0) {
        return d1;
    }
 
    return d2;
}
 
PLL get_csum_less_pos(int pp, int val) {
    return query_csum_less_pos(1, 1, n, pp, n, val, 0);
}
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // FastIO;
    
    scanf("%d %d", &n, &q);
    FOR(i, 1, n) {
        scanf("%lld", &ara[i]);
        update_range(1, 1, n, i, i, ara[i]);
    }
 
    FOR(i, 1, q) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int pos;
            LL val;
            scanf("%d %lld", &pos, &val);
            /// get position(pp) in (1, pos) which is less than or equal to val
 
            int lo = get_less_eq_pos_prefix(pos, val);
            if(lo == -1) {
                continue;
            }
 
            /// set (pp, pos) with val
            update_range(1, 1, n, lo, pos, val);
        }
        else {
            int pos; 
            LL val;
            scanf("%d %lld", &pos, &val);
            // cout << "hola" << endl;
            int pp = pos;
            int ans = 0;
            while(pp != -1) {
                PLL ri = get_csum_less_pos(pp, val);
                if(ri.F == 0) {
                    pp = get_less_eq_pos_suffix(ri.F + 1, val);
                    continue;
                }
                val -= ri.S;
                ans += ri.F - pp + 1;
                pp = get_less_eq_pos_suffix(ri.F + 1, val);
                // cout << pp << endl;
            }
            // cout << ans << "\n";
            printf("%d\n", ans);
        }
    }
 
    return 0;
}
/**
 * tags: segment tree, lazy propogation
*/