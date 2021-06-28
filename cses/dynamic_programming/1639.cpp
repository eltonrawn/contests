#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string a, b;
int n, m;
int dp[5010][5010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    n = a.size();
    m = b.size();

    for(int i = 0; i < n; i++) {
        dp[i][m] = n - i;
    }
    for(int i = 0; i < m; i++) {
        dp[n][i] = m - i;
    }
    dp[n][m] = 0;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            dp[i][j] = 1000000000;
            if(a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1];
            
            /// remove i or add j
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j]);

            /// remove j or add i
            dp[i][j] = min(dp[i][j], 1 + dp[i][j + 1]);
            
            /// replace i or j
            dp[i][j] = min(dp[i][j], 1 + dp[i + 1][j + 1]);

            // cout << i << " " << j << " : " << dp[i][j] << endl;
        }
        
    }
    cout << dp[0][0] << endl;
    return 0;
}
/**
*/