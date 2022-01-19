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
int par[SZ];
int perm[SZ];
int root;
int cost[SZ], ans[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            adjl[i].clear();
        }
        for(int u = 1; u <= n; u++) {
            int v;
            cin >> v;
            par[u] = v;
            if(u == v) {
                root = u;
                continue;
            }
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            cin >> perm[i];
        }
        set<int> st;
        st.insert(root);
        
        cost[root] = -1;
        int past_val = -1;
        bool valid = 1;
        for(int i = 1; i <= n; i++) {
            int u = perm[i];
            if(st.find(u) == st.end()) {
                valid = 0; break;
            }
            st.erase(u);

            past_val = max(past_val + 1, cost[ par[u] ] + 1);
            cost[u] = past_val;
            ans[u] = past_val - cost[par[u]];
            if(u == root) ans[u] = 0;

            for(int v: adjl[u]) {
                if(v == par[u]) continue;
                st.insert(v);
            }
        }
        if(!valid) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
