#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string s, t;

int dp[510][1010][2];

int func(int p1, int p2, bool chk) {
    if(p2 == t.size()) return 0;
    if(s[p1] != t[p2]) {
        return 0;
    }
    if(dp[p1][p2][chk] != -1) {
        return dp[p1][p2][chk];
    }
    int ans = 1;

    // if(chk) {
    //     ans = max(ans, func(p1, p2 + 1, 0));
    // }
    // ans = max(ans, func(p1, p2 + 1, 0));
    

    if(p1 - 1 >= 0) {
        ans = max(ans, 1 + func(p1 - 1, p2 + 1, 0));
    }
    if(p1 + 1 < s.size() && chk) {
        ans = max(ans, 1 + func(p1 + 1, p2 + 1, 1));
    }
    return dp[p1][p2][chk] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> s >> t;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < t.size(); j++) {
                for(int k = 0; k < 2; k++)
                    dp[i][j][k] = -1;
            }
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = max(ans, func(i, 0, 1));
            // cout << i << " : " << func(i, 0, 1) << endl;
        }
        if(ans == t.size()) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/**
*/
