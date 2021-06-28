#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL dp[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 6; j++)
            if(i - j >= 0)
                dp[i] += dp[i - j], dp[i] %= MOD;

    cout << dp[n] << endl;
    return 0;
}
/**
*/
