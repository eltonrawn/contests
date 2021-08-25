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
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        LL n;
        cin >> n;
        LL cnt = 0;
        int ans = 0;
        int i = 1;
        for(i = 1; i <= n; i+=2) {
            cnt += i; ans++;
            if(cnt >= n) {
                // cout << ans << endl; break;
                break;
            }
        }
        i -= 2;
        while(cnt < n) {
            ans++;
            cnt += i;
        }
        cout << ans << endl;
    }
    return 0;
}
/**


*/
