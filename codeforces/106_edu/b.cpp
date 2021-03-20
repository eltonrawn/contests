#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string s;
int dp[110][2][2];

int func(int pos, bool one, bool last) {
    if(pos == s.size()) {
        return 1;
    }
    if(dp[pos][one][last] != -1) {
        return dp[pos][one][last];
    }

    int ans = 0;
    /// removing
    if(last == 0) {
        ans = max(ans, func(pos + 1, one, 1));
    }
    
    if(one && s[pos] == '0') {

    }
    else {
        /// not removing
        ans = max(ans, func(pos + 1, s[pos] == '1' ? 1: one, 0));
    }
    // cout << pos << " " << one << " " << last << " : " << ans << endl;
    return dp[pos][one][last] = ans;
    
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> s;
        MEM(dp, -1);
        if(func(0, 0, 0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
/**
*/
