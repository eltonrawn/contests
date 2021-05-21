#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int p[SZ], h[SZ], sz[SZ];
vector<int> adjl[SZ];

int get_sz(int u, int par) {
    int ans = p[u];
    for(int v: adjl[u]) {
        if(v == par) continue;
        ans += get_sz(v, u);
    }
    return sz[u] = ans;
}

bool func(int u, int par) {
    // cout << u << " : " << sz[u] << " " << h[u] << endl;
    if((sz[u] + h[u]) % 2) return 0;
    int ugood = (sz[u] + h[u]) / 2;
    int ubad = sz[u] - ugood;
    // cout << u << " : " << ugood << " " << ubad << endl;
    if(ugood < 0 || ubad < 0) return 0;

    int mnbad = min(ubad, p[u]);
    ubad -= mnbad;
    p[u] -= mnbad;
    if(p[u] > ugood) return 0;
    ugood -= p[u];

    bool ans = 1;
    for(int v: adjl[u]) {
        if(v == par) continue;
        if((sz[v] + h[v]) % 2) return 0;
        int vgood = (sz[v] + h[v]) / 2;
        int vbad = sz[v] - vgood;
        if(vgood < 0 || vbad < 0) return 0;
        // cout << "v " << v << " : " << vgood << " " << vbad << endl;

        if(vgood > ugood) return 0;
        ugood -= vgood;
        mnbad = min(ubad, vbad);
        ubad -= mnbad;
        vbad -= mnbad;
        if(vbad > ugood) return 0;
        ugood -= vbad;
        ans = min(ans, func(v, u));
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        for(int i = 1; i <= n; i++) {
            adjl[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        get_sz(1, 0);
        // for(int i = 1; i <= n; i++) {
        //     cout << i << " : " << sz[i] << endl;
        // }
        cout << (func(1, 0) ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
*/
