#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
vector<PLL> adjl[SZ];
LL dp[SZ][2];

LL func(int u, bool is_back, int par) {
    if(dp[u][is_back] != -1) return dp[u][is_back];
    // LL all_back_cost = 0;
    vector< vector<LL> > all_back_cost;
    for(PII vw: adjl[u]) {
        int v = vw.first;
        LL w = vw.second;
        if(v == par) continue;
        // all_back_cost += func(v, 1, u);
        all_back_cost.push_back({w + func(v, 1, u), v, w});
    }
    sort(all_back_cost.begin(), all_back_cost.end(), greater< vector<LL> >());
    
    LL all_back_k_minus_1_cost = 0;
    for(int i = 0; i < min(k - 1, (int)all_back_cost.size()); i++) {
        all_back_k_minus_1_cost += all_back_cost[i][0];
    }
    LL all_back_k_cost = 0;
    for(int i = 0; i < min(k, (int)all_back_cost.size()); i++) {
        all_back_k_cost += all_back_cost[i][0];
    }
    // cout << u << " " << all_back_k_minus_1_cost << " " << all_back_k_cost << endl;

    LL ans = 0;
    if(is_back) {
        ans += all_back_k_minus_1_cost;
    }
    else {
        for(int i = 0; i < all_back_cost.size(); i++) {
            LL back_cost = all_back_cost[i][0];
            int v = all_back_cost[i][1];
            LL w = all_back_cost[i][2];
            /// taking current as not back
            if(i < k) {
                ans = max(ans, all_back_k_cost + func(v, 0, u) - func(v, 1, u));
            }
            else {
                ans = max(ans, all_back_k_minus_1_cost + w + func(v, 0, u));
            }
        }
    }
    return dp[u][is_back] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0, -1) << endl;
    return 0;
}
/**
start: 9:45 pm
*/
