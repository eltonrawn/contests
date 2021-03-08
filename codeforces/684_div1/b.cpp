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

// A hash function used to hash a pair of any kind 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

int n, m, k;
vector<int> adjl[100010];
int deg[100010];
// map<PII, int> mp;
// unordered_map<PII, int, hash_pair> mp;
unordered_set<int> us[100010];

void solve_case() {
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    // mp.clear();
    FOR(i, 1, n) {
        adjl[i].clear();
        deg[i] = 0;
        us[i].clear();
    }
    FOR(i, 1, m) {
        int a, b;
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        int u = min(a, b); int v = max(a, b);
        adjl[u].PB(v); adjl[v].PB(u);
        deg[u]++; deg[v]++;
        // mp[{u, v}] = 1;
        us[u].insert(v);
        us[v].insert(u);
    }
    set<PII> st;
    FOR(i, 1, n) {
        st.insert({deg[i], i});
    }
    // cout << "hola" << endl;
    while(!st.empty()) {
        PII top = (*st.begin());
        int u = top.S;
        if(top.F >= k) {
            /// ans of 1st type
            // cout << "1 " << st.size() << "\n";
            printf("1 %d\n", (int)st.size());
            for(PII ele: st) {
                // cout << ele.S << " ";
                printf("%d ", ele.S);
            }
            // cout << "\n";
            printf("\n");
            return;
        }
        else if(top.F  == k - 1) {
            /// check if this is clique
            vector<int> vvs;
            bool chk = 1;
            for(int v: adjl[u]) {
                if(deg[v] >= k - 1) {
                    vvs.push_back(v);
                }
            }
            if(vvs.size() < k - 1) {
                chk = 0;
            }
            for(int i = 0; i < vvs.size() && chk; i++) {
                for(int j = i + 1; j < vvs.size() && chk; j++) {
                    int a = vvs[i]; int b = vvs[j];
                    int v1 = min(a, b); int v2 = max(a, b);
                    // if(mp[{v1, v2}] == 0) {
                    //     chk = 0;
                    // }
                    if(us[v1].find(v2) == us[v1].end()) {
                        chk = 0;
                    }
                }
            }
            if(chk) {
                printf("2\n%d", u);
                // cout << "2\n";
                // cout << u;
                for(int v: vvs) {
                    // cout << " " << v;
                    printf(" %d", v);
                }
                printf("\n");
                // cout << "\n";
                return;
            }
        }
        /// remove this edge
        st.erase({deg[u], u});
        for(int v: adjl[u]) {
            if(deg[v] == 0)
                continue;
            st.erase({deg[v], v});
            deg[u]--;
            deg[v]--;
            st.insert({deg[v], v});
        }
    }
    // cout << -1 << "\n";
    printf("-1\n");
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);tt
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        solve_case();
    }
    return 0;
}
/**
*/
