#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
double ara[4010];
bool vis[4010][2010];
double dp[4010][2010];

double func(int pos, int taken) {
    if(pos > 2 * n) {
        if(taken != n) return 1000000000;
        return 0;
    }
    if(vis[pos][taken]) {
        return dp[pos][taken];
    }
    double ans = 1000000000;
    if(taken != n) {
        /// going up
        double tmp = ceil(ara[pos]) - ara[pos] + func(pos + 1, taken + 1);
        if(abs(tmp) < abs(ans)) {
            ans = tmp;
        }
    }
    /// goind down

    double tmp = floor(ara[pos]) - ara[pos] + func(pos + 1, taken);
    if(abs(tmp) < abs(ans))
        ans = tmp;

    // cout << ara[pos] << " " << floor(ara[pos]) << " " << ceil(ara[pos]) << endl;
    // cout << pos << " " << taken << " : " << ans << endl;
    vis[pos][taken] = 1;
    return dp[pos][taken] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= 2 * n; i++) {
        cin >> ara[i];
    }

    cout << fixed << setprecision(3) << abs(func(1, 0)) << endl;

    return 0;
}
/**
start: 9:52
end: 
*/
