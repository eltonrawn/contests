#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 2000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;



int n;
int no_div[SZ];

void nod() {
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            no_div[j]++;
}

LL dp[SZ];
// LL func(int len) {
//     if(len <= 2) {
//         return 1;
//     }
//     if(dp[len] != -1) return dp[len];
//     int ans = 0;

//     int kk = len;
//     gen_divisors(len);
//     for(int dd: divisors) {
//         if(dd == 1) continue;
//         if((len / dd) % 2 == 0) ans++;
//     }

//     int lim = len - 2;
//     for(int i = 0; i <= lim; i += 2) {
//         LL tmp = func(i);
//         ans += tmp;
//         ans %= MOD;
//         // cout << len << " " << i << " : " << tmp << endl;
//     }
    
//     return dp[len] = ans;
// }

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    nod();
    LL cc = 0;
    for(int len = 2; len <= n * 2; len += 2) {
        LL ans = 0;
        ans += no_div[len/2];
        ans += cc;
        ans %= MOD;
        dp[len] = ans;

        cc += dp[len];
        cc %= MOD;
        // cout << len << " : " << ans << endl;
    }
    cout << dp[n * 2] << endl;
    // memset(dp, -1, sizeof(dp));
    // cout << func(n * 2) << endl;
    return 0;
}
/**
 * 
 * tags: number of divisors, nod, sieve
*/
