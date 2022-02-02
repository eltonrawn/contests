#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class cmp {
public:
    bool operator()(PII a, PII b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int n, k;
// vector<int> adjl[SZ];
set<int> adjst[SZ];

/// {no_of_adj_leaf, node}
set<PII, cmp> mxst;
int adj_leaf[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            adjst[i].clear();
            adj_leaf[i] = 0;
        }
        mxst.clear();
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            // adjl[u].push_back(v);
            // adjl[v].push_back(u);

            adjst[u].insert(v);
            adjst[v].insert(u);
        }
        for(int u = 1; u <= n; u++) {
            if(adjst[u].size() == 1) {
                int v = *adjst[u].begin();
                // adjst[u].erase(adjst[u].begin());
                adj_leaf[v]++;
            }
        }
        for(int u = 1; u <= n; u++) {
            mxst.insert({adj_leaf[u], u});
        }
        int ans = 0;
        while(!mxst.empty()) {
            PII top = *mxst.begin(); mxst.erase(mxst.begin());
            // cout << "nn : " << top.second << " " << top.first << endl;
            if(top.first < k) break;
            ans++;
            int u = top.second;
            vector<int> rere;
            int taken = 0;
            for(int v: adjst[u]) {
                if(taken == k) break;
                if(adjst[v].size() == 1) {
                    rere.push_back(v);
                    taken++;
                }
            }
            for(int v: rere) {
                adjst[v].clear();
                adjst[u].erase(v);
                mxst.erase({adj_leaf[v], v});
            }
            if(adjst[u].size() == 1) {
                int v = *adjst[u].begin();
                mxst.erase({adj_leaf[v], v});
                adj_leaf[v]++;
                mxst.insert({adj_leaf[v], v});
            }
            adj_leaf[u] -= k;
            mxst.insert({adj_leaf[u], u});
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
