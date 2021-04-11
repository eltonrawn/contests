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

int n, p;
int ara[MX], ans[MX];
set<PII> st;
bool vis[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> p;
        st.clear();
        FOR(i, 1, n) {
            vis[i] = 0;
            ans[i] = p;
        }
        FOR(i, 1, n) {
            cin >> ara[i];
            st.insert({ara[i], i});
        }

        for(PII val: st) {
            int gcd = val.F;
            for(int i = val.S - 1; i >= 1; i--) {
                gcd = __gcd(ara[i], gcd);
                if(gcd != val.F) {
                    break;
                }
                ans[i] = min(ans[i], gcd);
                if(vis[i]) {
                    break;
                }
                vis[i] = 1;
            }

            gcd = val.F;
            for(int i = val.S + 1; i <= n; i++) {
                gcd = __gcd(ara[i], gcd);
                if(gcd != val.F) {
                    break;
                }
                ans[i - 1] = min(ans[i - 1], gcd);
                if(vis[i]) {
                    break;
                }
                vis[i] = 1;
            }
            vis[ val.S ] = 1;
        }
        LL res = 0;
        FOR(i, 1, n - 1) {
            // cout << i << " : " << ans[i] << endl;
            res += (LL)ans[i];
        }
        cout << res << "\n";

    }
    return 0;
}
/**
*/
