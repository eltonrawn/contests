#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str[1010];
int dp[1010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(str[i][j] == '*')
                dp[j] = 0;
            else if(j != 0)
                dp[j] += dp[j - 1];
            dp[j] %= MOD;
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
/**
*/
