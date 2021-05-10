#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL s, make;
vector<int> adjl[SZ];
vector<LL> cost[SZ];

/// {difference to substract, w, no_of_leave}
/// {difference -> (w * no_of_leave) - (w / 2 * no_of_leave)}
multiset< pair<LL, pair<LL, int> > > ms;

int func(int u, int par) {
    int tot_leave = 0;
    for(int i = 0; i < adjl[u].size(); i++) {
        int v = adjl[u][i];
        LL w = cost[u][i];
        if(v == par) continue;
        int no_of_leave = func(v, u);
        tot_leave += no_of_leave;
        LL half_w = w / 2;
        ms.insert({(w * no_of_leave) - (half_w * no_of_leave), {w, no_of_leave}});
        make += (w * no_of_leave);
    }
    return (tot_leave == 0) ? 1 : tot_leave;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> s;
        for(int i = 1; i <= n; i++) {
            adjl[i].clear(); cost[i].clear();
        }
        ms.clear(); make = 0;
        for(int i = 1; i < n; i++) {
            int u, v; LL w;
            cin >> u >> v >> w;
            
            adjl[u].push_back(v);
            cost[u].push_back(w);
            
            adjl[v].push_back(u);
            cost[v].push_back(w);
        }
        func(1, 0);
        int ans = 0;
        while(make > s) {
            auto it = ms.end(); it--;
            pair<LL, pair<LL, int> > top = *it;
            ms.erase(it);
            make -= top.first; ans++;
            top.second.first = top.second.first / 2;
            LL half_w = top.second.first / 2;
            top.first = (top.second.first * top.second.second) - (half_w * top.second.second);
            ms.insert(top);
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
