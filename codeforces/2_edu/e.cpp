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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int c[MX];
vector<int> adjl[MX];
int lev[MX];
int pp[MX];

void func(int u, int par) {
    lev[u] = lev[par] + 1;
    pp[u] = par;
    for(int v: adjl[u]) {
        if(v == par) {
            continue;
        }
        func(v, u);
    }
}

class cmp1 {
public:
    bool operator()(PII a, PII b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

set<PII, cmp1> st;
LL rep[MX], totcol[MX], ans[MX], mxcnt[MX];
map<int, LL> cntsm[MX], cnt[MX];

void update(int u, int col, int fr) {
    if(cnt[ rep[u] ][col] == 0) {
        totcol[ rep[u] ]++;
    }

    cntsm[ rep[u] ][ cnt[ rep[u] ][col] ] -= col;
    cnt[ rep[u] ][col] += fr;
    cntsm[ rep[u] ][ cnt[ rep[u] ][col] ] += col;

    mxcnt[ rep[u] ] = max(mxcnt[ rep[u] ], cnt[ rep[u] ][col]);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    FOR(i, 1, n) {
        cin >> c[i];
    }
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adjl[u].PB(v);
        adjl[v].PB(u);
    }
    func(1, 0);

    FOR(i, 1, n) {
        st.insert({lev[i], i});
    }

    for(PII val: st) {
        int u = val.S;
        if(adjl[u].size() == 1 && u != 1) {
            rep[u] = u;
            cnt[ rep[u] ][ c[u] ] = 1;
            cntsm[ rep[u] ][ cnt[ rep[u] ][ c[u] ] ] += c[u];
            totcol[ rep[u] ] = 1;
            mxcnt[ rep[u] ] = cnt[ rep[u] ][ c[u] ];
            
            ans[u] = cntsm[ rep[u] ][ mxcnt[ rep[u] ] ];
            // cout << u << " : " << c[u] << endl;
            continue;
        }
        int mx = -1;
        for(int v: adjl[u]) {
            if(v == pp[u]) {continue;}
            if(totcol[rep[v]] > mx) {
                mx = totcol[rep[v]];
                rep[u] = rep[v];
            }
        }

        for(int v: adjl[u]) {
            if(v == pp[u]) {continue;}
            if(rep[v] == rep[u]) {continue;}
            // cout << u << " " << v << endl;
            for(auto it: cnt[ rep[v] ]) {
                int col = it.first;
                int fr = it.second;
                update(u, col, fr);
            }
        }

        int col = c[u];
        update(u, col, 1);
        
        ans[u] = cntsm[ rep[u] ][ mxcnt[ rep[u] ] ];   

    }

    FOR(i, 1, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
/**
 * tags: dsu on tree, heavy light trick
*/
