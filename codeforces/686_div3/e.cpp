#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> adjl[SZ];
int sub[SZ], par[SZ];
bool vis[SZ];
PII back_edge;

int f1(int u, int pr) {
    // cout << u << " " << pr << endl;
    par[u] = pr;
    vis[u] = 1;
    int total = 0;
    for(int v: adjl[u]) {
        if(v == pr) continue;
        if(vis[v]) {
            /// back edge
            back_edge = {u, v};
            // cout << "bb : " << u << " " << v << endl;
            continue;
        }
        total += f1(v, u);
    }
    return sub[u] = 1 + total;
}

LL ans;

void f2(int u, int ch) {
    // cout << "f2 : " << u << " " << ch << endl;
    if(u != back_edge.first) {
        LL part1 = sub[ch];
        LL part2 = sub[u] - sub[ch];
        ans += part1 * part2;
        f2(par[u], u);
    }
    else {
        LL part1 = sub[ch];
        LL part2 = sub[1] - sub[ch];
        ans += part1 * part2;
    }
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
            adjl[i].clear();
            sub[i] = 0;
            par[i] = 0;
            vis[i] = 0;
        }
        ans = 0;
        for(int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        f1(1, 0);
        // cout << back_edge.first << " " << back_edge.second << endl;

        f2(par[back_edge.second], back_edge.second);

        // cout << "ans : " << ans << " ";
        ans += (n * (n - 1LL)) / 2LL;
        cout << ans << endl;

    }
    return 0;
}
/**
*/
