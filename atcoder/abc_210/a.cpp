#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL n, a, x, y;
    cin >> n >> a >> x >> y;
    if(a > n) {
        cout << n * x << endl;
    }
    else {
        cout << (a * x) + ((n - a) * y) << endl;
    }
    return 0;
}
/**
*/
