#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
LL dp[2][11][1 << 10];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int mask = 0; mask < (1 << n); mask++) {
        int cm = mask;
        for(int k = 0; k < n - 1; k++) {
            if(cm & (1 << k)) continue;
            if(cm & (1 << (k + 1))) break;
            cm = cm | (1 << k);
            cm = cm | (1 << (k + 1));
        }
        if(cm == (1 << n) - 1)
            dp[m & 1][0][mask] = 1;
    }

    for(int j = m - 1; j >= 0; j--) {
        int id = j & 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int mask = 0; mask < (1 << n); mask++) {
                dp[id][i][mask] = 0;
                int shifted_mask = (mask >> 1);
                int nid = id;
                int next_pos = i + 1;
                if(i == n - 1) {
                    next_pos = 0;
                    nid = id ^ 1;
                }
                if(mask & (1 << 0)) {
                    /// first bit is already fulfilled
                    dp[id][i][mask] += dp[nid][next_pos][shifted_mask];
                }
                else {
                    /// place 1X2
                    dp[id][i][mask] += dp[nid][next_pos][shifted_mask | (1 << (n - 1))];
                    
                    /// place 2X1
                    if(i != n - 1 && !(mask & (1 << 1)))
                        dp[id][i][mask] += dp[nid][next_pos][shifted_mask | (1 << 0)];
                }

                dp[id][i][mask] %= MOD;
            }
        }
    }
    cout << dp[0][0][(1 << n) - 1] << endl;
    return 0;
}
/**
00100101
00100000
11011111


1 2 4 8
  1 1
*/
