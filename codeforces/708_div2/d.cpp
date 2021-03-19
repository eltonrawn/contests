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

int n;
LL dp[2][5010];
int tag[5010];
LL score[5010];

LL dpff() {
    MEM(dp, 0);
    FOR(i, 2, n) {
        int cur = i % 2;
        int past = (i - 1) % 2;

        FOR(j, 1, i - 1) {
            dp[cur][j] = dp[past][j];
        }

        LL mx = 0;

        /// if current is going back to i - 1
        if(tag[i] != tag[i - 1]) {
            dp[cur][i - 1] = max(dp[cur][i - 1], abs(score[i] - score[i - 1]));
        }
        
        

        /// if current is going back from i - 2 to 1
        ROF(j, i - 2, 1) {
            if(tag[j + 1] != tag[i]) {
                mx = max(dp[past][j + 1] + abs(score[i] - score[j + 1]), mx);
            }

            if(tag[j] != tag[i]) {
                dp[cur][j] = max(dp[cur][j], mx + abs(score[i] - score[j]));
            }
        }

        /// if current is not going back
        if(tag[1] != tag[i]) {
            mx = max(dp[past][1] + abs(score[i] - score[1]), mx);
        }
        dp[cur][i] = max(dp[cur][i], mx);
    }

    int cur = n % 2;
    LL ans = 0;
    FOR(i, 1, n) {
        ans = max(ans, dp[cur][i]);
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            cin >> tag[i];
        }
        FOR(i, 1, n) {
            cin >> score[i];
        }
        cout << dpff() << "\n";
    }
    return 0;
}
/**
 * 3061438384057
 * 3354115974734
*/
