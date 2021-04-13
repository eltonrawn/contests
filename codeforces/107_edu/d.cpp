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

int k;
int g[30][30], edge_no[30];
string ans;

void find_euler_path() {
    // vector<vector<int>> g(n, vector<int>(n));
    // reading the graph in the adjacency matrix

    vector<int> deg(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j)
            deg[i] += g[i][j];
    }

    int first = 0;
    while (first < k && !deg[first])
        ++first;
    if (first == k) {
        cout << -1;
        return;
    }

    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < k; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];

    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        int i;
        for (i = 0; i < k; ++i)
            if (g[v][i])
                break;
        if (i == k) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (g[i][j])
                bad = true;
        }
    }

    if (bad) {
        cout << -1;
    } else {
        for (int x : res) {
            // cout << x << " ";
            ans += x + 'a';
        }
        // cout << res.size() << endl;

    }
}

void solve() {
    MEM(g, 0);
    int edge = 0;
    FOR(i, 0, k - 1) {
        FOR(j, i + 1, k - 1) {
            // if(i == j) {
            //     g[i][i] = 1;
            //     edge += 2;
            //     continue;
            // }
            edge += 2;
            g[i][j] = 2;
            g[j][i] = 2;
            // cout << i << " " << j << endl;
        }
    }
    ans.clear();
    find_euler_path();
    // cout << k << " : " << edge << " " << ans.size() - 1 << "\n";
    string tmp = ans;
    ans.clear();
    bool sisi[30];MEM(sisi, 0);
    FOR(i, 0, (int)tmp.size() - 1) {
        if(sisi[ tmp[i] - 'a' ] == 0 && tmp[i] != tmp.back()) {
            sisi[ tmp[i] - 'a' ] = 1;
            ans += tmp[i];
        }
        ans += tmp[i];
    }
    // cout << ans << endl;
    
    
    
    return;

}

int n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    
    cin >> n >> k;

    if(k == 1) {
        FOR(i, 1, n) {
            cout << 'a';
        }
        cout << endl;
        return 0;
    }
    solve();
    // cout << ans << endl;
    
    while(n) {
        if(ans.size() > n) {
            break;
        }
        cout << ans;
        n -= ans.size();
    }
    FOR(i, 0, n - 1) {
        cout << ans[i];
    }
    cout << endl;


    return 0;
}
/**
 * tags: euler circuit, euler path
*/
