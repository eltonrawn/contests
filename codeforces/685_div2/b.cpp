#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, q;
string str;
int le, ri;
int dp[110][110][2][2];

int func(int p1, int p2, bool is_con, bool is_start) {
    
    if(p2 == ri + 1) {
        if(is_con) return 0;
        return 1;
    }
    if(p1 == str.size()) {
        return 0;
    }
    if(dp[p1][p2][is_con][is_start] != -1) {
        return dp[p1][p2][is_con][is_start];
    }

    int ans = 0;
    /// not taking
    if(is_start) {
        ans = max(ans, func(p1 + 1, p2, 0, is_start));
    }
    else {
        ans = max(ans, func(p1 + 1, p2, is_con, is_start));
    }
        

    /// taking
    if(str[p1] == str[p2]) {
        ans = max(ans, func(p1 + 1, p2 + 1, is_con, 1));
    }
    return dp[p1][p2][is_con][is_start] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> q;
        cin >> str;
        for(int i = 1; i <= q; i++) {
            /// 100
            cin >> le >> ri;
            le--; ri--;
            memset(dp, -1, sizeof(dp));
            cout << (func(0, le, 1, 0) == 1 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
/**
*/
