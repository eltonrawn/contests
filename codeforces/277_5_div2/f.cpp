#include<bits/stdc++.h>

using namespace std;

// #define MOD 998244353
#define SZ 510
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m, mod;
string str[SZ];

int com_dp[510][3];

LL get_com(int pos, int left) {
    if(pos == 0) {
        if(left) return 0;
        return 1;
    }
    if(com_dp[pos][left] != -1) return com_dp[pos][left];
    LL ans = 0;
    // place one here
    if(left)
        ans += get_com(pos - 1, left - 1);
    
    if(ans >= mod) ans -= mod;
    
    /// place nothing
    ans += get_com(pos - 1, left);
    if(ans >= mod) ans -= mod;

    return com_dp[pos][left] = ans;
}

int dp[510][510];

LL func(int pos, int no_cmpl, int no_one, int no_zero) {
    if(pos == n) {
        return 1;
    }
    // cout << pos << " " << no_cmpl << endl;

    // only no_cmplt matters. you can calculate no_one based on how many rows have passed; same for no_zero
    if(dp[pos][no_cmpl] != -1) {
        return dp[pos][no_cmpl];
    }
    
    LL ans = 0;
    /// taking both from no_one
    if(no_one >= 2) {
        ans += get_com(no_one, 2) * func(pos + 1, no_cmpl + 2, no_one - 2, no_zero);
        ans %= mod;
    }

    /// taking both from no_zero
    if(no_zero >= 2) {
        ans += get_com(no_zero, 2) * func(pos + 1, no_cmpl, no_one + 2, no_zero - 2);
        ans %= mod;
    }

    /// takin one from no_one and another from no_zero
    if(no_zero && no_one) {
        LL tmp = (get_com(no_zero, 1) * get_com(no_one, 1));
        tmp %= mod;
        ans += tmp * func(pos + 1, no_cmpl + 1, no_one + 1 - 1, no_zero - 1);
        ans %= mod;
    }

    return dp[pos][no_cmpl] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> mod;
    for(int i = 0; i < m; i++) cin >> str[i];
    // don't need to check validity mentioned in problemset

    int no_cmpl = 0, no_one = 0, no_zero = 0;
    for(int j = 0; j < n; j++) {
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            if(str[i][j] == '1') cnt++;
        }
        if(cnt == 2) no_cmpl++;
        if(cnt == 1) no_one++;
        if(cnt == 0) no_zero++;
    }
    memset(dp, -1, sizeof(dp));
    memset(com_dp, -1, sizeof(com_dp));

    // cout << no_cmpl << " " << no_one << " " << no_zero << endl;
    cout << func(m, no_cmpl, no_one, no_zero) << endl;
    return 0;
}
/**

start: 10:25 pm
end: 11:26 pm
duration: 1 hour
comment: did a stupid mistake of not returning from a function. -_-

*/
