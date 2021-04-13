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
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL bm(LL base, LL power) {    //bm represents bigmod
    if(power == 0)  {
        return 1;
    }
    if(power % 2 == 0)  {
        LL ret = bm(base, power / 2);
        return (ret * ret) % MOD;
    }
    else    {
        return (base * bm(base, power - 1)) % MOD;
    }
}

PLL dp[MX][3];
bool vis[MX][3];

PLL func(int pos, int turn) {
    /// returns {ans, no_of_ways}
    if(pos == 0) {
        if(turn == 2) {
            return {1, 1};
        }
        return {0, 1};
    }
    if(vis[pos][turn]) {
        return dp[pos][turn];
    }
    PLL ans = {0, 0};
    /// placing blue
    ans.F += func(pos - 1, 0).F;
    ans.S += func(pos - 1, 0).S;

    /// placing red
    if(turn == 1) {
        ans.S += func(pos - 1, 0).S;
        ans.F += func(pos - 1, 0).S + func(pos - 1, 0).F;
    }
    else {
        ans.S += func(pos - 1, turn + 1).S;
        ans.F += func(pos - 1, turn + 1).F;
    }

    ans.F %= MOD;
    ans.S %= MOD;

    vis[pos][turn] = 1;
    // cout << pos << " " << turn << " : " << ans.F << endl;
    return dp[pos][turn] = ans;
}

int n, m;
string str[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    MEM(vis, 0);
    // cout << func(4, 0).F << endl;
    cin >> n >> m;
    FOR(i, 0, n - 1) {
        cin >> str[i];
    }
    int tot = 0;
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            if(str[i][j] == 'o') {
                tot++;
            }
        }
    }
    LL ans = 0;

    FOR(i, 0, n - 1) {
        for(int j = 0; j < m; j++) {
            int k = j;
            int tm = 0;
            while(k < m && str[i][k] == 'o') {
                tm++;k++;
            }
            if(tm == 0) continue;
            ans += func(tm, 0).F * bm(2, tot - tm);
            ans %= MOD;
            j = k - 1;
        }
    }

    FOR(j, 0, m - 1) {
        for(int i = 0; i < n; i++) {
            int k = i;
            int tm = 0;
            while(k < n && str[k][j] == 'o') {
                tm++;k++;
            }
            if(tm == 0) continue;
            ans += func(tm, 0).F * bm(2, tot - tm);
            ans %= MOD;
            i = k - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
/**
 * tags: dp, counting dp, number of ways dp
*/
