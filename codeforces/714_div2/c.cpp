#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 1000000007
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL dp[10][200010];

LL func(int digit, int m) {
    if(dp[digit][m] != -1) {
        return dp[digit][m];
    }

    if(m == 0 || m < (10 - digit)) {
        return 1;
    }
    LL ans = 0;
    ans += func(1, m - (10 - digit));
    ans += func(0, m - (10 - digit));
    ans %= MOD;
    return dp[digit][m] = ans;
}

int n, m;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    MEM(dp, -1);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        LL ans = 0;
        while(n) {
            ans += func(n % 10, m);
            n /= 10;

            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
*/
