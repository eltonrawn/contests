#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 400010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }

        ara[0] = ara[n + 1] = 0;
        LL ans = 0;
        int past = 0;
        for(int i = 1; i <= n; i++) {
            LL tmp = max(0LL, ara[i] - max(ara[i - 1], ara[i + 1]));
            ans += tmp;
            ara[i] -= tmp;
        }

        for(int i = 1; i < n; i++) {
            ans += labs(ara[i] - ara[i + 1]);
        }
        ans += ara[1];
        ans += ara[n];
        
        cout << ans << endl;
    }
    return 0;
}
/**
*/
