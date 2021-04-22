#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[2010];
int sum = 0;

int dp[101][200001];

int func(int pos, int ss) {
    if(pos == n) {
        if(ss == sum / 2) {
            return 1;
        }
        return 0;
    }
    if(dp[pos][ss] != -1) {
        return dp[pos][ss];
    }
    int ans = 0;
    /// taking
    ans = max(ans, func(pos + 1, ss + ara[pos]));
    
    /// not taking
    ans = max(ans, func(pos + 1, ss));
    return dp[pos][ss] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        sum += ara[i];
    }

    memset(dp, -1, sizeof(dp));
    if((sum % 2) || func(0, 0) == 0) {
        cout << 0 << endl;
        return 0;
    }

    while(1) {
        for(int i = 1; i <= n; i++) {
            if(ara[i] % 2) {
                cout << 1 << endl << i << endl;
                return 0;
            }
            ara[i] /= 2;
        }
    }
    return 0;
}
/**
*/
