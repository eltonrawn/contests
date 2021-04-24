#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        LL ans = 0;
        while(n >= 2050) {
            LL make = 2050;
            while(make * 10 <= n) {
                make *= 10;
            }
            n -= make;
            ans++;
        }
        if(n != 0) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
