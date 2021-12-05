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
bool vis[SZ];
int mx;

void dfs(int u) {
    mx = max(mx, u);
    if(vis[u]) return;
    vis[u] = 1;
    for(int v: adjl[u]) {
        dfs(v);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    
    int ans = 0;
    mx = 1;
    while(mx <= n) {
        int st = mx;
        dfs(mx);
        for(int i = st; i <= mx; i++) {
            if(vis[i] == 0) {
                dfs(i);
                ans++;
            }
        }
        mx++;
    }
    cout << ans << endl;

    return 0;
}
/**
start: 1:32 pm
end: 1:47 pm
duration: 15 mins
*/
