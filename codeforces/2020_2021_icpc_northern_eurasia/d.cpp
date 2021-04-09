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

int n, d;
LL ara[MX];
double dp[MX][10];
pair< pair<int, int>, int > path[MX][10];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> d;
    FOR(i, 1, n) {
        cin >> ara[i];
    }

    // dp[1][ ara[1] % 10 ] = ara[1];
    // path[ 1 ][ ara[1] % 10 ] = {{0, 0}, 1};
    FOR(i, 0, n) {
        FOR(j, 0, 9) {
            dp[i][j] = -1.0;
        }
    }

    FOR(i, 1, n) {
        
        FOR(j, 0, 9) {
            int sec = (ara[i] * (LL)j) % 10;

            if((dp[i - 1][j] >= 0) && (dp[i - 1][j] + log10(ara[i]) > dp[i][sec])) {
                // cout << "1 " << i << " " << j << " : " << dp[i - 1][j] + log10(ara[i]) << " " << dp[i][sec] << endl;
                path[i][sec] = {{i - 1, j}, 1};
                dp[i][ sec ] = dp[i - 1][j] + log10(ara[i]);
            }
        }

        FOR(j, 0, 9) {
            if(dp[i - 1][ j ] > dp[i][j]) {
                // cout << "2 " << i << " " << j << " : " << dp[i - 1][ j ] << " " << dp[i][j] << endl;
                path[i][j] = {{i - 1, j}, 0};
                dp[i][ j ] = dp[i - 1][ j ];
            }
        }

        
        if(log10(ara[i]) > dp[i][ ara[i] % 10 ]) {
            // cout << "3 " << i << " : " << log10(ara[i]) << " " << dp[i][ ara[i] % 10 ] << endl;
            dp[i][ ara[i] % 10 ] = log10(ara[i]);
            path[i][ ara[i] % 10 ] = {{0, 0}, 1};
        }
    }

    // cout << dp[n][d] << endl;

    if(dp[n][d] < 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<LL> ans;
    int x = n, y = d;
    while(x > 0) {
        int px = path[x][y].F.F;
        int py = path[x][y].F.S;

        if(path[x][y].S) {
            ans.PB(ara[x]);
        }

        x = px;
        y = py;
    }
    // ans.PB();

    cout << ans.size() << endl;
    for(LL val: ans) {
        cout << val << " ";
    }
    cout << endl;

    // cout << dp[n][d] << endl;
    return 0;
}
/**
 * tags: dp, iterative dp
*/
