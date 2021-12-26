#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 500010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL bm(LL base, LL power) {    //bm represents bigmod
    if(power == 0)  {
        return 1;
    }
    if(power % 2 == 0)  {
        LL ret = bm(base, power / 2);
        return (ret * ret) % MOD;
    }
    else    {
        return (base * bm(base, power - 1)) % MOD;
    }
}

int n;
int ara[SZ];
vector<int> indices[SZ];
LL dp[SZ][3];

LL func(int pos, int yoyo) {
    if(dp[pos][yoyo] != -1) return dp[pos][yoyo];
    int val = ara[pos];

    LL ans = 0;
    int curnxtpos = upper_bound(indices[val].begin(), indices[val].end(), pos) - indices[val].begin();

    // take this
    if(yoyo == 1) {
        ans++;
        // /// ans++, as we can end here

        /// ignore this/don't take this
        if(curnxtpos != indices[val].size()) {
            ans += func(indices[val][curnxtpos], 1);
            if(ans >= MOD) ans -= MOD;
        }

        /// take current and nextone same as current.
        if(curnxtpos != indices[val].size()) {
            ans += func(indices[val][curnxtpos], 1);
            if(ans >= MOD) ans -= MOD;
        }

        /// take current and nextone same as next/middle (curr_val + 1) one
        int midnxtpos = upper_bound(indices[val + 1].begin(), indices[val + 1].end(), pos) - indices[val + 1].begin();
        if(val + 1 <= n && midnxtpos != indices[val + 1].size()) {
            ans += func(indices[val + 1][midnxtpos], 1);
            if(ans >= MOD) ans -= MOD;
        }

        /// take current and nextone same as last(curr_val + 2) one
        int nxtnxtpos = upper_bound(indices[val + 2].begin(), indices[val + 2].end(), pos) - indices[val + 2].begin();
        if(val + 2 <= n && nxtnxtpos != indices[val + 2].size()) {
            ans += func(indices[val + 2][nxtnxtpos], 2);
            if(ans >= MOD) ans -= MOD;
        }
    }

    if(yoyo == 2) {
        // take current one
        int total = indices[val].size() - curnxtpos;

        if(val - 2 >= 0) {
            int prevnxtpos = upper_bound(indices[val - 2].begin(), indices[val - 2].end(), pos) - indices[val - 2].begin();
            total += indices[val - 2].size() - prevnxtpos;
        }
        ans += bm(2, total);
        if(ans >= MOD) ans -= MOD;
        
        /// or ignore this one
        if(curnxtpos != indices[val].size()) {
            ans += func(indices[val][curnxtpos], 2);
            if(ans >= MOD) ans -= MOD;
        }
    }
    return dp[pos][yoyo] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            /// initialize
            for(int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
            indices[i].clear();
        }
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            indices[ ara[i] ].push_back(i);
        }
        LL ans = 0;
        
        if(indices[0].size() > 0) {
            ans += func(indices[0][0], 1);
            if(ans >= MOD) ans -= MOD;
        }
        if(indices[1].size() > 0) {
            ans += func(indices[1][0], 2);
            if(ans >= MOD) ans -= MOD;
        }
        
        // cout << "ans : ";
        cout << ans << endl;
    }
    return 0;
}
/**
start: 2:27 pm
failed to do it in time. solved after a day.
comment: there's an elegant solution in tutorial, please check that.
tags: dp, repeat
*/
