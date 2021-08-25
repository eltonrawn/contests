#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 400010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<int> adj[SZ], adj_rev[SZ];
bool used[SZ];
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int n, m;
int is_con[SZ];

void dfs3(int u) {
    for(int v: adj[u]) {
        if(is_con[v] == -1) continue;
        is_con[v] = -1;
        dfs3(v);
    }
}

void dfs4(int u) {
    is_con[u] = 1;
    for(int v: adj[u]) {
        if(is_con[v]) continue;
        dfs4(v);
    }
}
PII edges[SZ];

int dp[SZ];
int func(int u) {
    if(dp[u] != -1) {
        return dp[u];
    }
    int ans = 0;
    for(int v: adj_rev[u]) {
        if(is_con[v] != 1) continue;
        func(v);
        ans += dp[v];
    }
    return dp[u] = min(2, ans);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            adj_rev[i].clear();
        }
        component.clear();
        order.clear();
        

        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj_rev[v].push_back(u);
            // if(u == v) is_con[u] = -1;
            edges[i] = {u, v};
        }
        // cout << "hola" << endl;
        for(int i = 1; i <= n; i++) is_con[i] = 0;
        dfs4(1);

        // cout << "hola" << endl;

        for(int i = 1; i <= m; i++) {
            int u = edges[i].first; int v = edges[i].second;
            if(u == v && is_con[u] == 1) is_con[u] = -1;
        }

        for(int i = 1; i <= n; i++) used[i] = 0;
        for (int i = 1; i <= n; i++)
            if (!used[i])
                dfs1(i);

        for(int i = 1; i <= n; i++) used[i] = 0;
        reverse(order.begin(), order.end());

        for (auto v : order) {
            if (!used[v]) {
                dfs2 (v);

                // ... processing next component ...
                // for(int cm: component)
                //     cout << cm << " ";
                // cout << endl;
                if(component.size() > 1) {
                    for(int cm: component)
                        if(is_con[cm] == 1)
                            is_con[cm] = -1;
                }

                component.clear();
            }
        }

        for(int i = 1; i <= n; i++) {
            if(is_con[i] == -1) {
                dfs3(i);
            }
        }
        // cout << "hola" << endl;

        for(int i = 1; i <= n; i++) dp[i] = -1;
        for(int i = 1; i <= n; i++) {
            if(is_con[i] == 1) {
                if(i == 1) {
                    dp[i] = 1; continue;
                }
                func(i);
            }
        }

        for(int i = 1; i <= n; i++) {
            if(is_con[i] != 1) {
                cout << is_con[i] << " "; continue;
            }
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
