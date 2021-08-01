#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<PII> vec;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({b, a});
    }
    LL ans = 0;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < m && n > 1; i++) {
        ans += (LL)(n - __gcd(n, vec[i].second)) * (LL)vec[i].first;
        n = __gcd(n, vec[i].second);
    }
    if(n > 1) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
/**
*/
