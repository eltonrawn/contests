#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> adjl[SZ], cc[SZ];
int indeg[SZ], vis[SZ];
vector<PII> ans;
set<PII> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            indeg[i] = 0; vis[i] = 0;
            adjl[i].clear(); cc[i].clear();
        }
        ans.clear(); st.clear();
        for(int i = 1; i <= m; i++) {
            int t, u, v;
            cin >> t >> u >> v;
            if(t == 0) {
                /// undirected
                adjl[u].push_back(v);
                cc[u].push_back(t);
                adjl[v].push_back(u);
                cc[v].push_back(t);
            }
            else {
                adjl[u].push_back(v);
                cc[u].push_back(t);
                indeg[v]++;
                ans.push_back({u, v});
            }
        }
        for(int i = 1; i <= n; i++) {
            st.insert({indeg[i], i});
        }
        bool chk = 1;
        while(!st.empty()) {
            PII top = *st.begin(); st.erase(st.begin());
            int ind = top.first;
            int u = top.second;
            if(ind > 0) {
                chk = 0; break;
            }
            vis[u] = 1;

            for(int i = 0; i < adjl[u].size(); i++) {
                int v = adjl[u][i];
                int t = cc[u][i];
                if(vis[v]) continue;
                if(t == 0) {
                    ans.push_back({u, v});
                }
                else {
                    st.erase({indeg[v], v});
                    indeg[v]--;
                    st.insert({indeg[v], v});
                }
            }
        }
        if(!chk) {
            cout << "NO" << endl; continue;
        }
        cout << "YES" << endl;
        for(PII val: ans) {
            cout << val.first << " " << val.second << endl;
        }
    }
    return 0;
}
/**
*/
