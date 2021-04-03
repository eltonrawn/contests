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

int n, k;
LL dp[1010][1010][2];

LL func(int pos, int val, bool dir) {
    if(val < 1) {
        return 0;
    }
    if(pos < 1 || pos > n) {
        return 1;
    }
    if(dp[pos][val][dir] != -1) {
        return dp[pos][val][dir];
    }
    LL ans = 0;
    if(dir == 0) {
        ans = func(pos + 1, val, dir) + func(pos - 1, val - 1, !dir);
    }
    else {
        ans = func(pos - 1, val, dir) + func(pos + 1, val - 1, !dir);
    }
    return dp[pos][val][dir] = ans % MOD;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        MEM(dp, -1);
        cout << func(1, k, 0) << endl;
    }
    return 0;
}
/**
*/
