#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector< vector<LL> > projects;
LL dp[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        projects.push_back({a, b, c});
    }

    sort(projects.begin(), projects.end());
    for(int i = projects.size() - 1; i >= 0; i--) {
        LL st = projects[i][0];
        LL ed = projects[i][1];
        LL cost = projects[i][2];
        vector<LL> vv; vv = {ed + 1, 0, 0};
        int nxt = upper_bound(projects.begin(), projects.end(), vv) - projects.begin();
        dp[i] = max(dp[i + 1], cost + dp[nxt]);
    }
    cout << dp[0] << endl;
    return 0;
}
/**
*/
