#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
int coins[110];
int dp[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> coins[i];
    
    dp[0] = 1;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= n; j++)
            if(i - coins[j] >= 0)
                dp[i] += dp[i - coins[j]], dp[i] %= MOD;

    cout << dp[x] << endl;
    return 0;
}
/**
*/
