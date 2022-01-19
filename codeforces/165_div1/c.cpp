#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector< vector<int> > ara;
set< int > adjl[SZ]; // this contains out edges
int out_cost[SZ], in_cost[SZ];
map<PII, int> cost_mp, pos_mp;
int ans[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ara.push_back({u, v, w});
        adjl[u].insert(v);
        adjl[v].insert(u);
        out_cost[u] += w;
        out_cost[v] += w;
        
        cost_mp[{u, v}] = w;
        cost_mp[{v, u}] = w;

        pos_mp[{u, v}] = i;
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: adjl[u]) {
            // going from u to v
            if(adjl[v].find(u) != adjl[v].end()) {
                adjl[v].erase(u);
                out_cost[v] -= cost_mp[{u, v}];
                in_cost[v] += cost_mp[{u, v}];
                // cout << u << " " << v << " : " << cost_mp[{u, v}] << endl;
                if(pos_mp[{u, v}]) {
                    ans[pos_mp[{u, v}]] = 0;
                }
                else {
                    ans[pos_mp[{v, u}]] = 1;
                }
                if(v != n && in_cost[v] == out_cost[v]) {
                    q.push(v);
                }
            }
        }
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
/**
start: 11:13 pm
end: 12:01 pm
duration: 50 mins
comment: too easy. took lots of time though.
*/