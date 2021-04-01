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

int n, m;
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
    }
    floyd_warshall();

    return 0;
}
/**
 * tags: graph, all pairs shortest path, 
*/
