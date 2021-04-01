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
#define MX 1010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[MX][MX];
int le[MX][MX];
int ri[MX][MX];
int up[MX][MX];
int down[MX][MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                cin >> ara[i][j];
            }
        }
        
        FOR(i, 1, n) {
            int cnt=0;
            FOR(j, 1, m) {
                if(ara[i][j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                le[i][j] = cnt;
            }
        }

        FOR(i, 1, n) {
            int cnt=0;
            ROF(j, m, 1) {
                if(ara[i][j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                ri[i][j] = cnt;
            }
        }

        FOR(j, 1, m) {
            int cnt=0;
            FOR(i, 1, n) {
                if(ara[i][j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                up[i][j] = cnt;
            }
        }

        FOR(j, 1, m) {
            int cnt=0;
            ROF(i, n, 1) {
                if(ara[i][j]) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }
                down[i][j] = cnt;
            }
        }

        LL ans = 0;

        FOR(i, 1, n) {
            FOR(j, 1, m) {
                int lim;

                /// consider up, left(double)
                lim = le[i][j] / 2;
                lim = min(lim, up[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider up(double), left
                lim = up[i][j] / 2;
                lim = min(lim, le[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider up, right(double)
                lim = ri[i][j] / 2;
                lim = min(lim, up[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider up(double), right
                lim = up[i][j] / 2;
                lim = min(lim, ri[i][j]);
                if(lim > 1)ans += lim - 1;

                ////////////////////////////////////////////

                /// consider down, left(double)
                lim = le[i][j] / 2;
                lim = min(lim, down[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider down(double), left
                lim = down[i][j] / 2;
                lim = min(lim, le[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider down, right(double)
                lim = ri[i][j] / 2;
                lim = min(lim, down[i][j]);
                if(lim > 1)ans += lim - 1;

                /// consider down(double), right
                lim = down[i][j] / 2;
                lim = min(lim, ri[i][j]);
                if(lim > 1)ans += lim - 1;

                // cout << i << " " << j << " : " << up[i][j] << " " << ri[i][j] << " : " << ans << endl;
            }
        }
        cout << "Case #" << tt << ": " << ans << "\n";

    }
    return 0;
}
/**
*/
