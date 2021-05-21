#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

struct Data {
    int node, ind;
    LL val;
};

class cmp {
public:
    bool operator()(Data a, Data b) {
        if(a.ind == b.ind) {
            if(a.val == b.val) {
                return a.node < b.node;
            }
            return a.val > b.val;
        }
        return a.ind < b.ind;
    }
};

int n;
LL a[SZ], b[SZ];
int indeg[SZ];

/// node, indeg
set<Data, cmp> st;
vector<int> adjl[SZ];
bool vis[SZ], v2[SZ];
vector<int> pr;

void func(int u) {
    if(v2[u]) return;
    v2[u] = 1;
    for(int v: adjl[u]) {
        func(v);
    }
    if(vis[u]) return;
    pr.push_back(u);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] == -1) continue;
        adjl[i].push_back(b[i]);
        indeg[b[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        st.insert({i, indeg[i], a[i]});
    }
    LL ans = 0;
    while(!st.empty()) {
        Data top = *st.begin(); st.erase(st.begin());
        int u = top.node;
        ans += a[u];
        if(top.val < 0) {
            for(int v: adjl[u]) {
                st.erase({v, indeg[v], a[v]});
                indeg[v]--;
                st.insert({v, indeg[v], a[v]});
            }
            continue;
        }
        
        vis[u] = 1;
        pr.push_back(u);
        for(int v: adjl[u]) {
            st.erase({v, indeg[v], a[v]});
            indeg[v]--;
            a[v] += a[u];
            st.insert({v, indeg[v], a[v]});
        }
    }
    for(int i = 1; i <= n; i++) {
        func(i);
    }
    cout << ans << endl;
    for(int u: pr) {
        cout << u << " ";
    }
    cout << endl;

    return 0;
}
/**
*/
