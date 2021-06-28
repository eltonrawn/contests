#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[SZ];
int dp[2][110];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    int cc = 1;
    
    for(int j = 1; j <= m; j++) {
        if(ara[1] == 0 || ara[1] == j)
            dp[cc][j] = 1;
    }

    for(int i = 2; i <= n; i++) {
        cc ^= 1;
        for(int j = 1; j <= m; j++) {
            dp[cc][j] = 0;
            
            if(ara[i] == 0 || ara[i] == j) {}
            else continue;

            for(int k = max(1, j - 1); k <= min(m, j + 1); k++) {
                dp[cc][j] += dp[cc ^ 1][k];
                dp[cc][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
        ans += dp[cc][i], ans %= MOD;
    cout << ans << endl;
    return 0;
}
/**
*/
