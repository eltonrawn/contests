#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, p, k;
string str;
int dp[SZ];
int x, y;

int func(int pos) {
    if(dp[pos] != -1) return dp[pos];
    int ans = 0;
    if(pos + k < str.size()) {
        int cc = 0;
        if(str[pos + k] == '0') cc = x;
        ans = cc + func(pos + k);
    }
    return dp[pos] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> p >> k;
        cin >> str;
        cin >> x >> y;
        for(int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        int ans = INT_MAX;
        int yoyo = 0;
        for(int i = p - 1; i < str.size(); i++) {
            int cc = 0;
            if(str[i] == '0') cc = x;
            ans = min(ans, yoyo + cc + func(i));
            yoyo += y;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
