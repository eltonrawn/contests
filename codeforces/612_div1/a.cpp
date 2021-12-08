#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 110
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
int vis[SZ];
int even = 0, odd = 0;
int dp[110][110][3];

int func(int pos, int e_used, int o_used, int last_parity) {
    if(pos > n) return 0;
    if(dp[pos][e_used][last_parity] != -1)
        return dp[pos][e_used][last_parity];

    if(ara[pos]) {
        int c = 0;
        if((ara[pos] % 2 == 0 && last_parity == 1) || (ara[pos] % 2 == 1 && last_parity == 0)) {
            c = 1;
        }
        return dp[pos][e_used][last_parity] = c + func(pos + 1, e_used, o_used, ara[pos] % 2);
    }

    int ans = 1000000000;
    if(e_used < even) {
        /// place even
        int c = 0;
        if(last_parity == 1) {
            c = 1;
        }
        ans = min(ans, c + func(pos + 1, e_used + 1, o_used, 0));
    }
    if(o_used < odd) {
        /// place odd
        int c = 0;
        if(last_parity == 0) {
            c = 1;
        }
        ans = min(ans, c + func(pos + 1, e_used, o_used + 1, 1));
    }

    return dp[pos][e_used][last_parity] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            vis[ara[i]] = 1;
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            if(i % 2) odd++;
            else even++;
        }
        memset(dp, -1, sizeof(dp));
        cout << func(1, 0, 0, 2) << endl;
        // cout << even << " " << odd << endl;
    // }
    return 0;
}
/**
start: 6:42 pm
end: 7:03 pm
duration: 21 mins
*/
