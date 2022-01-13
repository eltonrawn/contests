#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 710
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
int dp[SZ][SZ][2];
bool is_conn[SZ][SZ];

int func(int le, int ri, bool is_left) {
    if(le > ri) {
        return 1;
    }
    if(le == ri) {
        int i = le;
        if((is_left && !is_conn[i][ri + 1]) || (!is_left && !is_conn[i][le - 1]))
            return 0;
        return 1;
    }
    if(dp[le][ri][is_left] != -1) return dp[le][ri][is_left];
    int ans = 0;
    for(int i = le; i <= ri; i++) {
        /// take i;
        if(le == 1 && ri == n) {
            ans = max(ans, min(func(le, i - 1, 1), func(i + 1, ri, 0))); continue;
        }
        if((is_left && !is_conn[i][ri + 1]) || (!is_left && !is_conn[i][le - 1]))
            continue;
        
        ans = max(ans, min(func(le, i - 1, 1), func(i + 1, ri, 0)));
    }
    return dp[le][ri][is_left] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    // n = 700;
    // int ans = 0;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i; j <= n; j++) {
    //         ans += j - i + 1;
    //     }
    // }
    // cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            is_conn[i][j] = 1;
            if(__gcd(ara[i], ara[j]) == 1) {
                is_conn[i][j] = 0;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    // cout << func(1, n, 0) << endl;
    cout << (func(1, n, 0) == 1 ? "Yes" : "No") << endl;
    return 0;
}
/**
start: 1:16 pm
end: 2:24 pm
duration: 1 hour 8 mins
comment: bad time as it is pretty common problem. 
although the reason it took time because of me forgetting the definition of bst.
tags: dp
*/
