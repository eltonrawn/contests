#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 5010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL a[SZ], b[SZ], ab[SZ], csum[SZ];

LL dp[SZ][SZ];

LL func(int le, int ri) {
    if(le > ri) {
        return 0;
    }
    if(dp[le][ri] != -1) {
        return dp[le][ri];
    }
    LL ans = a[ri] * b[le];
    if(le != ri) {
        ans += a[le] * b[ri];
    }
    ans += func(le + 1, ri - 1);

    return dp[le][ri] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        ab[i] = a[i] * b[i];
        csum[i] = csum[i - 1] + ab[i];
    }
    LL ans = csum[n];
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            /// reverse i to j
            ans = max(ans, func(i, j) + csum[n] - (csum[j] - csum[i - 1]));
        }
    }
    cout << ans << endl;

    return 0;
}
/**
*/
