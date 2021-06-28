#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/**
   2 ** 8
   2 ** 4 * 2 ** 4
   2 ** (4 + 4)
*/

LL bm(LL base, LL power) {
    if(power == 0) return 1;
    if(power % 2)
        return (base * bm(base, power - 1)) % MOD;
    LL ret = bm(base, power / 2);
    return (ret * ret) % MOD;
}

LL mod_inv(LL num) {
    return bm(num, MOD - 2);
}

int n;
LL dp[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x = (n * (n + 1)) / 2;
    if(x % 2) {
        cout << 0 << endl; return 0;
    }
    x /= 2;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }
    cout << ((dp[x] * mod_inv(2)) % MOD) << endl;
    return 0;
}
/**
*/
