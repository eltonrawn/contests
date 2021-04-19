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

LL cc = 1000000000000000000LL + 1LL;
LL dp[100010][2];
LL n, k;

// LL func(int pos, bool chk) {
//     if(pos > n) {
//         return !chk;
//     }
//     if(dp[pos][chk] != -1) {
//         return dp[pos][chk];
//     }
//     LL ans = 0;
//     if(chk == 0) {
//         /// placing as it is
//         ans += func(pos + 1, chk);
//         ans = min(ans, cc);

//         /// not placing
//         ans += func(pos + 1, 1);
//         ans = min(ans, cc);
//     }
//     else if(chk) {
//         /// not placing
//         ans += func(pos + 1, chk);
//         ans = min(ans, cc);

//         /// placing
//         ans += func(pos + 1, 0);
//         ans = min(ans, cc);
//     }
//     return dp[pos][chk] = ans;
// }

LL func(int pos, bool chk) {
    if(pos == n) {
        if(chk == 0) {
            return 1;
        }
        return 0;
    }
    if(dp[pos][chk] != -1) {
        return dp[pos][chk];
    }
    LL ans = 0;
    if(chk == 0) {
        /// placing next_pos as it is
        ans += func(pos + 1, chk);
        ans = min(ans, cc);

        /// not placing next_pos
        ans += func(pos + 1, 1);
        ans = min(ans, cc);
    }
    else if(chk) {
        /// not placing next_pos
        ans += func(pos + 1, chk);
        ans = min(ans, cc);

        /// placing next_pos as it is
        ans += func(pos + 1, 0);
        ans = min(ans, cc);
    }
    return dp[pos][chk] = ans;
}
vector<LL> ans;


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        MEM(dp, -1);
        ans.clear();
        LL made = 0, last = 0;
        vector<LL> tmp;
        for(int i = 1; i <= n; i++) {
            // cout << i << " : " << made + func(i, 0) << endl;
            if(made + func(i, 0) < k) {
                made += func(i, 0);
                tmp.PB(i);
                continue;
            }
            last = made + func(i, 0);
            
            ans.PB(i);
            reverse(tmp.begin(), tmp.end());
            for(LL val: tmp) {
                ans.PB(val);
            }
            tmp.clear();
        }
        // cout << "made : " << made << endl;
        // cout << "last : " << last << endl;
        if(last != k) {
            cout << -1 << endl;
            continue;
        }
        for(LL val: ans) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
