#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL dp[SZ][5];

void calculate_dp() {
    /**
     * status = 0; nothing continues
     * status = 1; only left continue
     * status = 2; only right continue
     * status = 3; both continue separately
     * status = 4; both continue together as a block
    */

    dp[0][0] = 1;

    for(int i = 1; i < SZ; i++) {
        for(int status = 0; status < 5; status++) {
            dp[i][status] = 0;
            int past_pos = i - 1;
            if(status == 0) {
                dp[i][status] += dp[past_pos][4];
                dp[i][status] += dp[past_pos][3];
                dp[i][status] += dp[past_pos][2];
                dp[i][status] += dp[past_pos][1];
                /// placing two separate blocks
                dp[i][status] += dp[past_pos][0];
                /// placing two as single block
                dp[i][status] += dp[past_pos][0];
            }
            else if(status == 1 || status == 2 || status == 3) {
                dp[i][status] += dp[past_pos][0];
                dp[i][status] += dp[past_pos][1];
                dp[i][status] += dp[past_pos][2];
                dp[i][status] += dp[past_pos][3];
            }
            else if(status == 4) {
                dp[i][status] += dp[past_pos][0];
                dp[i][status] += dp[past_pos][4];
            }
            dp[i][status] %= MOD;
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    calculate_dp();
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        cout << dp[n][0] << endl;
    }
    return 0;
}
/**
*/
