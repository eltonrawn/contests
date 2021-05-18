#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
int c[SZ];

int solve(int col) {
    int ans = 0;
    for(int i = 1; i <= n; ) {
        while(i <= n && c[i] == col) {
            i++;
        }
        if(i > n) break;
        // cout << "i : " << i << endl;
        ans++;
        i += k;
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        int ans = INT_MAX;
        for(int i = 1; i <= 100; i++) {
            // cout << i << " : " << solve(i) << endl;
            ans = min(ans, solve(i));
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
