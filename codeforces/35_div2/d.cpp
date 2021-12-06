#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
int ara[110];
int dp[110][10010];

int func(int pos, int rest) {
    if(pos > n) {
        return 0;
    }
    if(dp[pos][rest] != -1) return dp[pos][rest];
    /// not taking
    int ans = func(pos + 1, rest);
    /// taking
    if((n - pos + 1) * ara[pos] <= rest) {
        ans = max(ans, 1 + func(pos + 1, rest - ((n - pos + 1) * ara[pos])));
    }

    return dp[pos][rest] = ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    cout << func(1, x) << endl;
    return 0;
}
/**
start: 10 pm
end: 10:08 pm
duration: 8 minutes
*/
