#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL l[SZ], r[SZ];
vector<int> adjl[SZ];

LL dp[SZ][2];

LL func(int u, int par, bool is_left) {
    if(dp[u][is_left] != -1) {
        return dp[u][is_left];
    }
    LL res = 0;
    LL ans = 0;

    /// taking left for current
    if(is_left) {
        /// parent is left
        ans = abs(l[par] - l[u]);
    }
    else {
        /// parent is right
        ans = abs(r[par] - l[u]);
    }
    if(u == 1) ans = 0;
    for(int v: adjl[u]) {
        if(v == par) continue;
        ans += func(v, u, 1);
    }
    res = max(res, ans);

    /// taking right for current
    if(is_left) {
        /// parent is left
        ans = abs(l[par] - r[u]);
    }
    else {
        /// parent is right
        ans = abs(r[par] - r[u]);
    }
    if(u == 1) ans = 0;

    for(int v: adjl[u]) {
        if(v == par) continue;
        ans += func(v, u, 0);
    }
    res = max(res, ans);

    return dp[u][is_left] = res;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
            adjl[i].clear();
            for(int j = 0; j < 2; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        cout << func(1, 1, 0) << endl;
    }
    return 0;
}
/**
*/
