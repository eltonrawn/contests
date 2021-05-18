#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int n, m, r, c;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m >> r >> c;
        int ans = 0;
        ans = max(ans, dist(1, 1, r, c));
        ans = max(ans, dist(1, m, r, c));
        ans = max(ans, dist(n, 1, r, c));
        ans = max(ans, dist(n, m, r, c));
        cout << ans << endl;
    }
    return 0;
}
/**
*/
