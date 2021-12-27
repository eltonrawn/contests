#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 10000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> adjl[SZ];
vector<PII> range[SZ];
set<int> idx;
int cur_ri[SZ];

int bfs(int le) {
    for(int i = 1; i <= n; i++) {
        ///
        cur_ri[i] = 0;
    }
    set<PII> q;
    cur_ri[1] = 1000000;
    q.insert({1000000, 1});
    while(!q.empty()) {
        auto it = q.end(); it--;
        PII front = *it;
        q.erase(it);
        
        int u = front.second;
        int u_ri = front.first;
        // cout << "u : " << u << endl;

        for(int i = 0; i < adjl[u].size(); i++) {
            int v = adjl[u][i];
            PII ran = range[u][i];
            if(le < ran.first) continue;
            int ri = min(u_ri, ran.second);

            if(cur_ri[v] < ri) {
                q.erase({cur_ri[v], v});
                cur_ri[v] = ri;
                q.insert({cur_ri[v], v});
            }
        }
    }
    // can be negative but doesn't matter;
    return cur_ri[n] - le + 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        int r1, r2;
        cin >> u >> v >> r1 >> r2;
        adjl[u].push_back(v);
        range[u].push_back({r1, r2});
        adjl[v].push_back(u);
        range[v].push_back({r1, r2});
        idx.insert(r1);
    }
    int ans = 0;
    for(int id: idx) {
        ans = max(ans, bfs(id));
    }
    if(ans == 0) {
        cout << "Nice work, Dima!" << endl;
    }
    else cout << ans << endl;
    
    return 0;
}
/**
start: 7:15 pm
end: 8:18 pm
duration: 1 hour
comment: was stuck in finding the solution. 1 hour is actually not bad for 2000. but have to do these under 30 mins.
*/
