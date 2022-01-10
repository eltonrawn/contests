#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
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

int n, m;
vector<Edge> edges;
// int cost;
vector<Edge> result;

bool skip(int pre, int lim, int val) {
    for(int i = 0; i < 31; i++) {
        if(((1 << i) & pre) && ((1 << i) && val)) {
            val = (~(1 << i)) & val;
        }
    }
    for(int i = 0; i < 31; i++) {
        if((1 << i) & val) {
            if(i > lim) return 1;
        }
    }
    return 0;
}

bool kruskal(int pre, int lim, bool is_bs) {
    parent.clear();parent.resize(n + 1);
    rank_of.clear();rank_of.resize(n + 1);
    result.clear();
    for(int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (Edge e : edges) {
        if(is_bs && skip(pre, lim, e.weight)) {
            continue;
        }
        if(!is_bs && (pre | e.weight) != pre) continue;

        if (find_set(e.u) != find_set(e.v)) {
            // cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    if(result.size() == n - 1) return 1;
    return 0;
    // set<int> st;
    // for(int i = 1; i <= n; i++) {
    //     st.insert(parent[i]);
    //     if(st.size())
    // }
}

int bs(int pre_val, int lim) {
    int lo = 0, hi = lim;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(kruskal(pre_val, mid, 1)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    // cout << pre_val << " " << lim << " " << lo << endl;
    return lo;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        edges.clear();
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        sort(edges.begin(), edges.end());
        int pre = 0;
        int lim = 31;
        while(true) {
            lim = bs(pre, lim - 1);
            pre = pre | (1 << lim);
            if(kruskal(pre, lim, 0)) {
                break;
            }
        }
        // cout << "ans : ";
        cout << pre << endl;
    }
    return 0;
}
/**
*/
