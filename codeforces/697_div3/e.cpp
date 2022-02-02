#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 3000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL dp[SZ][SZ];
LL ncr(int n, int r) {
    if(r == 0) return 1;
    if(r == 1) return n;
    if(n == r) return 1;
    if(dp[n][r] != -1) {
        return dp[n][r];
    }
    return dp[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % MOD;
}

int n, k;
int ara[SZ];



int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        sort(ara + 1, ara + 1 + n, greater<int>());
        // LL total = 0;
        // for(int i = 1; i <= k; i++) {
            
        // }
        int target = ara[k];
        int tot = 0;
        int r = 0;
        for(int i = 1; i <= k; i++) {
            if(ara[i] == target)
                r++;
        }
        for(int i = 1; i <= n; i++) {
            if(ara[i] == target)
                tot++;
        }
        cout << ncr(tot, r) << endl;
    }
    return 0;
}
/**
*/
