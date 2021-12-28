#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> adjl[SZ];
int buds, child;
bool sp_child;

int func(int u, int par) {
    int ff = adjl[u].size();

    /// subtracting 1 for parent
    if(u != 1) ff--;

    for(int v: adjl[u]) {
        if(v == par) continue;
        ff += func(v, u);
    }
    if(u == 1) return 0;
    if(ff) {
        /// this is a bud
        buds++;
        return -1;
    }
    /// this is a child
    child++;
    if(par == 1) {
        // cout << "sp : " << u << endl;
        sp_child = 1;
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        // n >= 2
        // if(n == 1) {
        //     cout << 1 << endl;
        //     continue;
        // }
        for(int i = 1; i <= n; i++) {
            adjl[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        buds = 0;
        child = 0;
        sp_child = 0;
        func(1, 0);
        // cout << buds << " " << child << " " << sp_child << endl;
        cout << child - buds + 1 - sp_child << endl;
    }
    return 0;
}
/**
start: 11:23 am
enc: 12:23 pm
duration 1 hour
comment: this was tricky. 1 hour not bad.
tags: repeat
*/
