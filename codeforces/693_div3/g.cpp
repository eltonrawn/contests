#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> adjl[SZ];
int dis[SZ], dp[SZ][2];

void bfs() {
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: adjl[u]) {
            if(dis[v] > dis[u] + 1) {
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
}

int func(int u, bool yo) {
    if(dp[u][yo] != -1) return dp[u][yo];
    int ans = dis[u];
    for(int v: adjl[u]) {
        if(dis[v] > dis[u]) {
            // able
            ans = min(ans, func(v, yo));
            continue;
        }
        if(yo == 0) {
            ans = min(ans, func(v, yo + 1));
        }
    }
    return dp[u][yo] = ans;
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
            adjl[i].clear();
            dis[i] = INT_MAX;
            dp[i][0] = dp[i][1] = -1;
        }
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adjl[u].push_back(v);
        }
        bfs();
        for(int i = 1; i <= n; i++) {
            cout << func(i, 0) << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
start: 6:16 pm
end: 6:40 pm
idea found: 6:31 pm
duration: 24 mins
comment: not bad
*/
