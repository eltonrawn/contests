#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
int price[SZ], page[SZ];
int dp[100010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> price[i];
    for(int i = 1; i <= n; i++)
        cin >> page[i];
    
    // dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], page[i] + dp[j - price[i]]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}
/**
*/
