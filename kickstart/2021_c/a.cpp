#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
string str;
LL dp[100010][2][2][2];

LL func(int le, int ri, bool is_lower, bool lower_lock, bool lower_ri) {
    if(le > ri) {
        if(lower_lock)
            return 0;

        if(is_lower || lower_ri)
            return 1;

        return 0;
    }
    if(dp[le][is_lower][lower_lock][lower_ri] != -1) {
        return dp[le][is_lower][lower_lock][lower_ri];
    }
    
    LL ans = 0;
    int lim = min(k, str[le] - 'a' + 1);
    if(is_lower) {
        lim = k;
    }
    for(int i = 1; i <= lim; i++) {
        if(is_lower || i < lim) {
            ans += func(le + 1, ri - 1, 1, 0, lower_ri);
            continue;
        }
        
        if(i < (int)str[ri] - 'a' + 1) {
            ans += func(le + 1, ri - 1, is_lower, 0, 1);
        }
        else if(i == (int)str[ri] - 'a' + 1) {
            ans += func(le + 1, ri - 1, is_lower, lower_lock, lower_ri);
        }
        else {
            ans += func(le + 1, ri - 1, is_lower, 1, lower_ri);
        }
    }
    ans %= MOD;
    // cout << le << " " << ri << " " << is_lower << " " << lower_lock << " " << lower_ri << " : " << ans << endl;
    return dp[le][is_lower][lower_lock][lower_ri] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        cin >> str;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    for(int l = 0; l < 2; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        cout << "Case #" << tt << ": ";
        cout << func(0, n - 1, 0, 0, 0) << endl;
    }
    return 0;
}
/**
*/
