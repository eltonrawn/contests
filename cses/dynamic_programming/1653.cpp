#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


const int inf = 1000000000;
int n, x;
int w[25];
PLL dp[1 << 20];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    dp[0] = {1, 0};
    for(int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {inf, inf};
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                PLL tmp = dp[mask & (~(1 << i))];
                if(tmp.second + w[i] <= x)
                    tmp.second += w[i];
                else
                    tmp.first++, tmp.second = w[i];
                dp[mask] = min(dp[mask], tmp);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}
/**
11
*/
