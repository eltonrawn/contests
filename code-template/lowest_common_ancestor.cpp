#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> adjl[SZ];

/**lowest common ancestor start */
int l;
int timer;
vector<int> tin, tout, lev;
vector<vector<int>> up;

void dfs(int v, int p, int lv)
{
    tin[v] = ++timer;
    up[v][0] = p;
    lev[v] = lv;

    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adjl[v]) {
        if (u != p)
            dfs(u, v, lv + 1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    lev.resize(n + 1);
    timer = 0;
    l = ceil(log2(n + 1));
    up.assign(n + 1, vector<int>(l + 1));
    dfs(root, root, 1);
}
/** lowest common ancestor end */

int get_dis(int u, int v) {
    int lc = lca(u, v);
    if(lc == u || lc == v) {
        return abs(lev[v] - lev[u]);
    }
    return abs(lev[v] - lev[lc]) + abs(lev[u] - lev[lc]);
}

int x, y, a, b, k;

bool get_qq() {
    if(get_dis(a, b) % 2 == k % 2 && get_dis(a, b) <= k) {
        return 1;
    }
    if((get_dis(a, x) + 1 + get_dis(y, b)) % 2 == k % 2 && get_dis(a, x) + 1 + get_dis(y, b) <= k) {
        return 1;
    }
    if((get_dis(a, y) + 1 + get_dis(x, b)) % 2 == k % 2 && get_dis(a, y) + 1 + get_dis(x, b) <= k) {
        return 1;
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    preprocess(1);

    int qq;
    cin >> qq;
    for(int i = 1; i <= qq; i++) {
        
        cin >> x >> y >> a >> b >> k;
        cout << (get_qq() ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
problem: cf_620_div2 e
tags: lowest common ancestor, lca, repeat, 2000
*/
