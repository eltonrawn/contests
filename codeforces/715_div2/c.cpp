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
#define MOD 998244353
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[2020];
LL dp[2020][2020];

LL func(int p1, int p2) {
    if(p1 > p2) {
        return 0;
    }
    if(dp[p1][p2] != -1) {
        return dp[p1][p2];
    }
    LL ans = INFL;
    ans = min(ans, ara[p2] - ara[p1] + func(p1 + 1, p2));
    ans = min(ans, ara[p2] - ara[p1] + func(p1, p2 - 1));
    // cout << p1 << " " << p2 << " : " << ans << endl;
    return dp[p1][p2] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    FOR(i, 0, n - 1) {
        cin >> ara[i];
    }
    sort(ara, ara + n);
    MEM(dp, -1);
    cout << func(0, n - 1) << endl;

    return 0;
}
/**
*/
