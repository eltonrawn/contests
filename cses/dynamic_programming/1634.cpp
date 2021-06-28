#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 110
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
int coins[SZ];
int dp[1000010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> coins[i];
    
    dp[0] = 0;
    for(int i = 1; i <= x; i++) {
        dp[i] = 100000000;
        for(int j = 1; j <= n; j++)
            if(i - coins[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    }
    if(dp[x] == 100000000) {
        cout << -1 << endl; return 0;
    }
    cout << dp[x] << endl;;


    return 0;
}
/**
*/
