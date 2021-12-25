#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> adjl[SZ];
map<PII, int> edge;
int color[SZ];
int col_freq[4];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[{u, v}] = 1;
        edge[{v, u}] = 1;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    int col = 1;
    for(int i = 1; i <= n; i++) {
        if(color[i]) continue;
        if(col > 3) {
            cout << -1 << endl;
            return 0;
        }
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(edge[{i, j}] == 0 && color[j]) {
                cout << -1 << endl;
                return 0;
            }
        }

        color[i] = col; col_freq[col]++;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(edge[{i, j}] == 0) {
                color[j] = col; col_freq[col]++;
            }
        }
        col++;
    }

    if(col != 4) {
        cout << -1 << endl;
        return 0;
    }

    /// this proves theres no common edge amon same color set
    for(int u = 1; u <= n; u++) {
        for(int v: adjl[u]) {
            if(color[u] == color[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    /// this proves every node is connected with every nodes from other sets.
    for(int u = 1; u <= n; u++) {
        if(adjl[u].size() != n - col_freq[color[u]]) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;


    return 0;
}
/**
start: 3:26 pm
end: 4:05 pm
duration: 40 mins
comment: missed corner case which I knew it all along. should have been faster.
*/
