#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m, k;
LL x[SZ];
set< PII > ab;
// , cd;
PII abara[SZ], cdara[SZ];
int h[SZ];
map<PII, int> adj_pos;
map<int, PII> adj_rev_pos;
vector<PII> adjl[SZ];


LL inf = 1000000000000000000LL;
/**
status = 0 /// no direction -> go_left, go_right, climb
status = 1 /// left -> go_left, climb
status = 2 /// right -> go_right, climb
*/
bool vis[SZ][3];
PLL dp[SZ][3];
PLL func(int u, int status) {
    if(u == adj_pos[{n, m}]) {
        // cout << "hi" << endl;
        return {0, 1};
    }
    PII xy = adj_rev_pos[u];
    if(vis[u][status]) return dp[u][status];

    PLL ans = {-1 * inf, 0};

    // climb
    for(PII v: adjl[u]) {
        if(func(v.first, 0).second) {
            ans.second = 1;
            ans.first = max(ans.first, v.second + func(v.first, 0).first);
        }
        
    }

    if(status == 0 || status == 1) {
        // go left
        auto it = ab.lower_bound({xy.first, xy.second});
        if(it != ab.begin()) {
            it--;
            PLL vv = *it;
            if(vv.first == xy.first && func(adj_pos[{vv.first, vv.second}], 1).second) {
                ans.second = 1;
                ans.first = max(ans.first, func(adj_pos[{vv.first, vv.second}], 1).first - (x[vv.first] * abs(vv.second - xy.second)));
            }
        }
    }
    if(status == 0 || status == 2) {
        // go right
        auto it = ab.upper_bound({xy.first, xy.second});
        if(it != ab.end()) {
            PII vv = *it;
            if(vv.first == xy.first && func(adj_pos[{vv.first, vv.second}], 2).second) {
                ans.second = 1;
                ans.first = max(ans.first, func(adj_pos[{vv.first, vv.second}], 2).first - (x[vv.first] * abs(vv.second - xy.second)));
            }
        }
    }
    vis[u][status] = 1;
    return dp[u][status] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        ab.clear(); ab.insert({n, m});
        // cd.clear();
        adj_pos.clear(); adj_rev_pos.clear();
        set<PII> st;
        st.insert({1, 1});
        st.insert({n, m});
        for(int i = 1; i <= k; i++) {
            int a, b, c, d, hh;
            cin >> a >> b >> c >> d >> hh;
            ab.insert({a, b});
            // cd.insert({c, d});
            abara[i] = {a, b};
            cdara[i] = {c, d};
            h[i] = hh;
            st.insert(abara[i]);
            st.insert(cdara[i]);
        }
        int cnt = 1;
        for(PII val: st) {
            adj_pos[val] = cnt;
            adj_rev_pos[cnt] = val;
            cnt++;
        }

        for(int i = 0; i <= cnt; i++) {
            adjl[i].clear();
            for(int j = 0; j <= 2; j++) {
                vis[i][j] = 0;
            }
        }

        for(int i = 1; i <= k; i++) {
            adjl[adj_pos[abara[i]]].push_back({adj_pos[cdara[i]], h[i]});
        }
        if(func(adj_pos[{1, 1}], 0).second == 0) cout << "NO ESCAPE" << endl;
        else cout << -1 * func(adj_pos[{1, 1}], 0).first << endl;
    }
    return 0;
}
/**
*/
