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

string x, y;
LL dp[1010][1010][2][2][4];

LL func(int p1, int p2, bool start, bool last, int both) {

    // cout << p1 << " " << p2 << " " << start << " " << last << endl;
    if(p1 > x.size() || p2 > y.size()) {
        return 0;
    }
    LL ans = 0;

    /// ending here
    if(start && (both == 3)) {
        ans++;
    }

    if(p1 == x.size() && p2 == y.size()) {
        return ans;
    }
    
    if(dp[p1][p2][start][last][both] != -1) {
        return dp[p1][p2][start][last][both];
    }
    
    // /// not started
    // if(start == 0) {
    //     if(p1 < x.size()) {
    //         ans += func(p1 + 1, p2, start, last);
    //     }
    //     if(p2 < y.size()) {
    //         ans += func(p1, p2 + 1, start, last);
    //     }
    //     if(p1 < x.size() && p2 < y.size()) {
    //         ans -= func(p1 + 1, p2 + 1, start, last);
    //     }
    // }

    /// start here or already started before
    if((p1 < x.size()) && (!start || (start && ((last == 0 && x[p1 - 1] != x[p1]) || (last == 1 && y[p2 - 1] != x[p1]))))) {
        ans += func(p1 + 1, p2, 1, 0, both | (1 << 0));
    }

    if(p2 < y.size() && (!start || (start && ((last == 0 && x[p1 - 1] != y[p2]) || (last == 1 && y[p2 - 1] != y[p2]))))) {
        ans += func(p1, p2 + 1, 1, 1, both | (1 << 1));
    }
    ans %= MOD;
    return dp[p1][p2][start][last][both] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> x >> y;
    
    MEM(dp, -1);

    LL ans = 0;
    FOR(i, 0, (int)x.size() - 1) {
        FOR(j, 0, (int)y.size() - 1) {
            ans += func(i, j, 0, 0, 0);
            // cout << i << " " << j << " : " << func(i, j, 0, 0, 0) << endl;
        }
    }
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
/**
 * tags: overcounting dp
*/
