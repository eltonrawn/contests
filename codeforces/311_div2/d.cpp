#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, m;
vector<int> adjl[SZ];
bool vis[SZ];
LL white, black;
bool col[SZ];

bool func(int u, int par) {
    vis[u] = 1;
    col[u] = !col[par];
    if(col[u] == 0) white++;
    else black++;
    bool ans = 1;
    for(int v: adjl[u]) {
        if(v == par) continue;
        if(vis[v] && col[v] == col[u]) {
            ans = 0; break;
        }
        if(vis[v]) continue;
        ans = min(ans, func(v, u));
    }
    return ans;
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
    vector<int> szs;
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        white = 0; black = 0;
        if(!func(i, 0)) {
            cout << "0 1" << endl;
            return 0;
        }
        ans += (white * (white - 1)) / 2;
        ans += (black * (black - 1)) / 2;
        szs.push_back(white + black);
    }
    sort(szs.begin(), szs.end(), greater<int>());

    if(szs[0] >= 3) cout << 1 << " " << ans << endl;
    else if(szs[0] == 1) {
        /// nc3
        cout << 3 << " " << (n * (n - 1) * (n - 2)) / 6 << endl;
    }
    else if(szs[0] == 2) {
        LL ans = 0;
        // LL baki = n;
        for(int sz: szs) {
            if(sz == 1) break;
            ans += n - 2;
        }
        cout << 2 << " " << ans << endl;
    }

    return 0;
}
/**
start: 12:15 pm
code start: 12:28 pm
end: 1 pm
duration: 45 mins
comment: bad time. missed a case.
*/
