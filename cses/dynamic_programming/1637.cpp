#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int dp[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        vector<int> digits;
        int digit = i;
        while(digit) {
            digits.push_back(digit % 10);
            digit /= 10;
        }
        dp[i] = 100000000;
        for(int dig: digits) {
            if(i - dig >= 0)
                dp[i] = min(dp[i], 1 + dp[i - dig]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
/**
*/
