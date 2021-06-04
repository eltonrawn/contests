#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

bool is_dig_available(int val, int digit) {
    while(val) {
        if(val % 10 == digit) return 1;
        val /= 10;
    }
    return 0;
}

int dp[1000];

int func(int digit) {
    dp[0] = 1;
    for(int i = 1; i < 1000; i++) {
        dp[i] = 0;
        for(int j = 1; j <= i; j++) {
            if(!is_dig_available(j, digit)) continue;
            dp[i] = max(dp[i], dp[i - j]);
        }
        int cnt = 0;
        for(int j = i; j >= max(i - digit + 1, 1); j--) {
            cnt += dp[j];
        }
        if(cnt == digit) return i;
    }
    return -1;
}


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // for(int i = 1; i <= 9; i++) {
    //     cout << i << " : " << func(i) << endl;
    // }
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        int q, d;
        cin >> q >> d;
        int mx = func(d);
        for(int i = 1; i <= q; i++) {
            int yoyo; cin >> yoyo;
            if(yoyo > mx) {
                cout << "YES" << endl;
            }
            else {
                cout << (dp[yoyo] == 0? "NO" : "YES") << endl;
            }

        }
    }
    return 0;
}
/**
*/
