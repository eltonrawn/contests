#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 501
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
int dp[SZ][SZ];


int cur_pos;
LL func(int pos, int small) {
    if(pos == n) return 1;
    if(dp[pos][small] != -1) {
        return dp[pos][small];
    }
    LL ans = 0;
    /// not taking it
    if(pos != cur_pos)
        ans += func(pos + 1, small);

    if(ans >= MOD) ans -= MOD;

    /// taking it
    if(ara[pos] == -1) {
        if(small) {
            ans += func(pos + 1, small - 1);
        }
        else if(pos < cur_pos) ans += func(pos + 1, small);
    }
    else {
        if(ara[pos] < ara[cur_pos] || (ara[pos] == ara[cur_pos] && pos < cur_pos)) {
            ans += func(pos + 1, small + 1);
        }
        else {
            ans += func(pos + 1, small);
        }
    }
    if(ans >= MOD) ans -= MOD;
    return dp[pos][small] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if(ch == '+') cin >> ara[i];
        else ara[i] = -1;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++) {
        if(ara[i] == -1) continue;
        memset(dp, -1, sizeof(dp));
        cur_pos = i;
        ans += func(0, 0) * ara[i] % MOD;
        if(ans >= MOD) ans -= MOD;
        // cout << ara[i] << " : " << func(0, 0) << endl;
    }
    cout << ans << endl;
    return 0;
}
/**
*/
