#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL g;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> g;
        LL sum = 0;
        LL ans = 0;
        // cout << "hi\n";
        for(int i = 0;; i++) {
            sum += i;
            if(sum >= g) break;
            if((g - sum) % (i + 1) == 0) {
                // int k = (g - sum) / (i + 1);
                ans++;
            }
        }
        cout << "Case #" << tt << ": ";
        cout << ans << endl;
    }
    return 0;
}
/**
 * 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17
 * k = 8
 * k + k + 1 + .............................. k + 9
 * 
 * (10 * k) + (0 + ..... + 9) = g
 * 
 * 62 + 63
 * k = 62
 * k + k + 1
 * (2 * k) + (0 + 1) = g
 * (2 * k) = g - (0 + 1)
 * 
 * 
 * 
*/
