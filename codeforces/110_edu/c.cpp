#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
LL dp[SZ][3];

LL func(int pos, int last) {
    if(pos == str.size())
        return 0;
    if((str[pos] - '0') == last)
        return 0;

    if(dp[pos][last] != -1)
        return dp[pos][last];
    
    LL ans = 1;

    if(str[pos] == '?') {
        if(last <= 1)
            ans += func(pos + 1, !last);
        else
            ans += func(pos + 1, last);
    }
    else {
        ans += func(pos + 1, str[pos] - '0');
    }
    return dp[pos][last] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> str;
        for(int i = 0; i < str.size(); i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }
        LL ans = 0;
        for(int i = 0; i < str.size(); i++) {
            ans += func(i, 2);
            // cout << i << " : " << func(i, 2) << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
