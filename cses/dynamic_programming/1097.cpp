#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 5010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];
LL dp[SZ][SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    LL sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> ara[i], sum += ara[i];


    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j)
                dp[i][j] = ara[i];
            else
                dp[i][j] = max(ara[i] - dp[i + 1][j], ara[j] - dp[i][j - 1]);
        }
    }

    cout << (sum + dp[1][n]) / 2LL << endl;
    return 0;
}
/**
*/
