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

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        LL sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            sum += ara[i];
        }
        double ans;
        LL taken = 0;
        sort(ara + 1, ara + n + 1);
        for(int i = 1; i <= n; i++) {
            taken += ara[i];
            double can = (taken / (double)i) + ((sum - taken) / (double)(n - i));
            if(i == 1) ans = can;
            else ans = max(ans, can);
        }
        cout << fixed << setprecision(13) << ans << endl;
    }
    return 0;
}
/**
*/
