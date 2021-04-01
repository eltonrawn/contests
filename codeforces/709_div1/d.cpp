#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m, q;
LL d[610][610];

void print_floyd() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}

void floyd_warshall() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    // print_floyd();
}

vector<int> adjl[610], cost[610];
LL rel_cost[610][610];
vector< pair < pair<int, int>, int > > edges;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // FastIO;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if(i == j) {continue;}
            d[i][j] = INFL;
        }
    }

    FOR(i, 1, m) {
        int u, v, w;
        // cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        d[u][v] = w;
        d[v][u] = w;
        edges.push_back({{u, v}, w});
    }
    floyd_warshall();
    
    // cin >> q;
    scanf("%d", &q);
    FOR(i, 1, q) {
        int u, v, w;
        // cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);

        if(d[u][v] > w) {
            continue;
        }

        adjl[u].PB(v);
        cost[u].PB(w);

        adjl[v].PB(u);
        cost[v].PB(w);
    }
    

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if(i == j) {
                continue;
            }
            
            LL mx = 0;
            for(int k = 0; k < (int)adjl[j].size(); k++) {
                int v = adjl[j][k];
                LL w = cost[j][k];
                mx = max(mx, w - d[i][v]);
            }
            rel_cost[i][j] = mx;
        }
    }

    int ans = 0;
    for(pair < pair<int, int>, int > edge: edges) {
        int v = edge.F.F;
        int i = edge.F.S;
        LL w = edge.S;

        for(int j = 1; j <= n; j++) {
            if(j == i) {
                continue;
            }

            if(rel_cost[i][j] - d[j][v] - w >= 0) {
                ans++;
                break;
            }
        }
    }

    // cout << ans << "\n";
    printf("%d\n", ans);

    return 0;
}
/**
 * tags: graph, all pairs shortest path, 
*/
