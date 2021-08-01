#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL row, col, cost;
LL ara[SZ][SZ];

bool is_val(int r, int c) {
    if(r >= 1 && r <= row && c >= 1 && c <= col)
        return 1;
    return 0;
}

LL inf = 10000000000000000LL;
LL dp[SZ][SZ][2][4];

LL func(int r, int c, bool initial, int tp) {
    if(dp[r][c][initial][tp] != -1) {
        return dp[r][c][initial][tp];
    }
    LL ans = inf;
    if(!initial)
        ans = ara[r][c];
    if(tp == 0) {
        /// going right;
        if(is_val(r, c + 1))
            ans = min(ans, cost + func(r, c + 1, 0, tp));

        /// going down
        if(is_val(r + 1, c))
            ans = min(ans, cost + func(r + 1, c, 0, tp));
    }

    if(tp == 1) {
        /// going right;
        if(is_val(r, c + 1))
            ans = min(ans, cost + func(r, c + 1, 0, tp));

        /// going up
        if(is_val(r - 1, c))
            ans = min(ans, cost + func(r - 1, c, 0, tp));
    }

    if(tp == 2) {
        /// going left;
        if(is_val(r, c - 1))
            ans = min(ans, cost + func(r, c - 1, 0, tp));

        /// going up
        if(is_val(r - 1, c))
            ans = min(ans, cost + func(r - 1, c, 0, tp));
    }

    if(tp == 3) {
        /// going left;
        if(is_val(r, c - 1))
            ans = min(ans, cost + func(r, c - 1, 0, tp));

        /// going down
        if(is_val(r + 1, c))
            ans = min(ans, cost + func(r + 1, c, 0, tp));
    }
    

    return dp[r][c][initial][tp] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col >> cost;
    
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            cin >> ara[i][j];
        }
    }

    LL ans = inf;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            for(int k = 0; k < 4; k++) {
                ans = min(ans, ara[i][j] + func(i, j, 1, k));
            }
        }
    }
    cout << ans << endl;

    
    return 0;
}
/**
*/
