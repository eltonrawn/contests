#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
LL a[SZ], b[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    LL gc = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++) {
        if(i == 2) gc = a[i] - a[1];
        gc = __gcd(gc, a[i] - a[1]);
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= m; i++) {
        cout << __gcd(a[1] + b[i], gc) << " ";
    }
    cout << endl;
    return 0;
}
/**
 * tags: number theory, gcd, euclidean algorithm
*/
