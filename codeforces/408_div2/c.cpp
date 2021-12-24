#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
vector<int> adjl[SZ];
multiset<int> ms;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        ms.insert(ara[i]);
    }

    for(int u = 1; u <= n; u++) {
        int mx = ara[u];
        ms.erase(ms.find(ara[u]));
        for(int v: adjl[u]) {
            mx = max(mx, ara[v] + 1);
            ms.erase(ms.find(ara[v]));
        }
        auto it = ms.end(); 
        if(it != ms.begin()) {
            it--;
            mx = max(mx, *it + 2);
        }

        for(int v: adjl[u]) {
            ms.insert(ara[v]);
        }
        ms.insert(ara[u]);
        ans = min(ans, mx);
    }
    cout << ans << endl;
    return 0;
}
/**
start: 7:28 pm
end: 8:21 pm
duration: 53 mins
comment: finding solution took time. disappointing.
*/
