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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
LL ara[MX];

struct Data  {
    LL sum, mx;
    Data()  {
        sum = 0;
        mx = -1;
    }
};

class Segtree {
public:
    Data tree[MX * 4];

    void init_tree(int ll, int rr, int pos) { //ll = left;rr = right
        if(ll == rr)    {
            tree[pos].sum = ara[ll];
            tree[pos].mx = ara[ll];
            return;
        }
        int mid = (ll + rr) / 2;
        init_tree(ll, mid, pos * 2);
        init_tree(mid + 1, rr, (pos * 2) + 1);
        
        tree[pos].sum = tree[pos * 2].sum + tree[(pos * 2) + 1].sum;
        tree[pos].mx = max(tree[pos * 2].mx, tree[(pos * 2) + 1].mx);
    }
    
    Data query(int ll, int rr, int pos, int t_l, int t_r) {  //t_l = target left
        if((ll >= t_l) && (rr <= t_r))  {
            return tree[pos];
        }
        
        if((ll > t_r) || (rr < t_l))   {
            return Data();
        }

        int mid = (ll + rr) / 2;
        Data left_v = query(ll, mid, pos * 2, t_l, t_r);
        Data right_v = query(mid + 1, rr, (pos * 2) + 1, t_l, t_r);

        left_v.sum += right_v.sum;
        left_v.mx = max(left_v.mx, right_v.mx);
        return left_v;
    }
    
    void update(int ll, int rr, int pos, int t_pos, LL t_val)    {
        if(t_pos < ll || t_pos > rr) {
            return;
        }
        if((ll == rr) && (rr == t_pos))   {
            tree[pos].mx = t_val;
            tree[pos].sum = t_val;
            return;
        }
        int mid = (ll + rr) / 2;

        update(ll, mid, pos * 2, t_pos, t_val);
        update(mid + 1, rr, (pos * 2) + 1, t_pos, t_val);

        tree[pos].sum = tree[pos * 2].sum + tree[(pos * 2) + 1].sum;
        tree[pos].mx = max(tree[pos * 2].mx, tree[(pos * 2) + 1].mx);
    }


    int query_next_pos_gre(int ll, int rr, int pos, int t_l, LL x) {  //t_l = target left
        if(ll == rr) {
            if(tree[pos].mx < x) {
                return n + 1;
            }
            return ll;
        }
        
        
        int mid = (ll + rr) / 2;
        if(t_l <= mid && tree[pos * 2].mx >= x) {
            
            int left_v = query_next_pos_gre(ll, mid, pos * 2, t_l, x);
            if(left_v != n + 1) {
                return left_v;
            }
        }

        if(tree[(pos * 2) + 1].mx < x) {
            return n + 1;
        }
        return query_next_pos_gre(mid + 1, rr, (pos * 2) + 1, t_l, x);
    }

};

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> m;
    FOR(i, 1, n) {
        cin >> ara[i];
    }
    Segtree tree = Segtree();
    tree.init_tree(1, n, 1);

    FOR(i, 1, m) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            // print sum(l, r)
            int l, r;
            cin >> l >> r;
            cout << tree.query(1, n, 1, l, r).sum << "\n";
        }
        else if(tp == 2) {
            // mod(l, r) % x
            
            int l, r; LL x;
            cin >> l >> r >> x;
            
            int pos = l;
            while(pos <= r) {
                pos = tree.query_next_pos_gre(1, n, 1, l, x);
                if(pos > r) {
                    break;
                }
                LL val = tree.query(1, n, 1, pos, pos).mx;
                tree.update(1, n, 1, pos, val % x);
                pos++;
            }
        }
        else if(tp == 3) {
            // a[k] = x
            
            int k; LL x;
            cin >> k >> x;
            tree.update(1, n, 1, k, x);

        }
    }

    return 0;
}
/**
 * tags: segment tree, segment tree with binary search
*/
