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
#define MOD 1000000007
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
LL dp[1010][1010][2];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;

        FOR(i, 0, k + 1) {
            FOR(j, 0, n + 1) {
                FOR(dir, 0, 1) {
                    if(j == n + 1 || j == 0 || i == 1) {
                        dp[i][j][dir] = 1;
                        continue;
                    }
                    dp[i][j][dir] = 0;
                }
            }
        }
        
        FOR(i, 2, k) {
            FOR(dir, 0, 1) {
                if(dir == 0) {
                    FOR(j, 1, n) {
                        dp[i][j][dir] = dp[i][j - 1][dir] + dp[i - 1][j + 1][!dir];
                        dp[i][j][dir] %= MOD;
                    }
                }
                else {
                    ROF(j, n, 1) {
                        dp[i][j][dir] = dp[i][j + 1][dir] + dp[i - 1][j - 1][!dir];
                        dp[i][j][dir] %= MOD;
                    }
                }
                // cout << i << " " << j << " " << dir << " : " << dp[i][j][dir] << endl;
            }
        }
        
        cout << dp[k][n][0] << endl;
    }
    return 0;
}
/**
*/
