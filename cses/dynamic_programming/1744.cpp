#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 510
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int dp[SZ][SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == j) continue;
            dp[i][j] = 1000000000;
            for(int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
            for(int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
/**
*/
