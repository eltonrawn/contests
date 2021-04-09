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
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class Segtree {
public:
    LL tree[MX * 4];
    void init_bro(int n) {
        init_tree(1, n, 1);
    }

    LL init_tree(int ll, int rr, int pos) { //ll = left;rr = right
        if((rr - ll) == 0)    {
            return tree[pos] = LLONG_MIN;
        }
        int mid = (ll + rr) / 2;
        LL left_v = init_tree(ll, mid, pos * 2);
        LL right_v = init_tree(mid + 1, rr, (pos * 2) + 1);
        return tree[pos] = max(left_v, right_v);
    }
    
    LL query(int ll, int rr, int pos, int t_l, int t_r) {  //t_l = target left
        if((ll >= t_l) && (rr <= t_r))  {
            return tree[pos];
        }
        else if((ll > t_r) || (rr < t_l))   {
            return LLONG_MIN;
        }
        else    {
            int mid = (ll + rr) / 2;
            LL left_v = query(ll, mid, pos * 2, t_l, t_r);
            LL right_v = query(mid + 1, rr, (pos * 2) + 1, t_l, t_r);
            return max(left_v, right_v);
        }
    }
    
    LL update(int ll, int rr, int pos, int t_pos, LL t_val)    {
        if((ll == rr) && (rr == t_pos))   {
            return tree[pos] = t_val;
        }
        int mid = (ll + rr) / 2;
        if(t_pos <= mid)    {
            return tree[pos] = max(update(ll, mid, pos * 2, t_pos, t_val), tree[(pos * 2) + 1]);
        }
        else    {
            return tree[pos] = max(update(mid + 1, rr, (pos * 2) + 1, t_pos, t_val), tree[(pos * 2)]);
        }
        
    }
};


int n;
int h[MX], a[MX];
LL dp[MX];

Segtree s1 = Segtree();
Segtree s2 = Segtree();

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    
    cin >> n;
    FOR(i, 1, n) {
        cin >> h[i];
    }
    FOR(i, 1, n) {
        cin >> a[i];
        dp[i] = LLONG_MIN;
    }

    s1.init_bro(n);
    s2.init_bro(n);

    dp[0] = 0;
    
    FOR(i, 1, n) {
        int pp = s1.query(1, n, 1, 1, h[i]);

        pp = max(0, pp);

        if(pp == 0) {
            if(i != 1) {
                dp[i] = a[i] + s2.query(1, n, 1, 1, i - 1);
            }
            dp[i] = max(dp[i], a[i] + dp[0]);
        }
        else {
            dp[i] = a[i] + s2.query(1, n, 1, pp, i - 1);
            dp[i] = max(dp[i], dp[pp]);
            // cout << i << "--> " << a[i] << " " << s2.query(1, n, 1, pp, i - 1) << endl;
        }
        
        // cout << i << " : " << pp << " " << dp[i] << endl;

        s2.update(1, n, 1, i, dp[i]);
        s1.update(1, n, 1, h[i], i);
    }
    cout << dp[n] << endl;

    return 0;
}
/**
 * tags: segment tree
*/
