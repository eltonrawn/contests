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

vector<int> parent, rank_of;

void make_set(int v) {
    parent[v] = v;
    rank_of[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_of[a] < rank_of[b])
            swap(a, b);
        parent[b] = a;
        if (rank_of[a] == rank_of[b])
            rank_of[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

int n;
vector<Edge> edges;
int cost;
vector<Edge> result;
// parent.resize(n);
// rank.resize(n);
int a[510][510], b[510][510];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> a[i][j];
            }
        }
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> b[i][j];
            }
        }
        FOR(i, 1, n) {int tmp;cin >> tmp;}
        FOR(i, 1, n) {int tmp;cin >> tmp;}

        edges.clear();
        int ans = 0;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                if(a[i][j] != -1) {
                    continue;
                }
                ans += b[i][j];
                edges.push_back({i, n + j, b[i][j]});
            }
        }


        parent.clear();parent.resize(n + n + 1);
        rank_of.clear();rank_of.resize(n + n + 1);
        result.clear();cost = 0;

        FOR(i, 1, n + n) {
            make_set(i);
        }
        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {
                ans -= e.weight;
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }
        cout << "Case #" << tt << ": ";
        cout << ans << "\n";

    }
    return 0;
}
/**
 * tags: mst, modified minimum spanning tree
 * 
*/
