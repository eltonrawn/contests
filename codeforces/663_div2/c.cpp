#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


LL n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    LL ans = 1;
    for(LL i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }

    LL sub = 1;
    for(int i = 1; i < n; i++) {
        sub *= 2;
        sub %= MOD;
    }
    ans = (((ans - sub) % MOD) + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
/**
 * 228388301
*/
