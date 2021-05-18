#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ], mx_bit[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 30; j++) {
            mx_bit[i] = (ara[i] & (1 << j)) ? j : mx_bit[i];
        }
        // cout << i << " : " << mx_bit[i] << endl;
    }

    for(int i = 2; i < n; i++) {
        if(mx_bit[i - 1] == mx_bit[i] && mx_bit[i] == mx_bit[i + 1]) {
            cout << 1 << endl;
            return 0;
        }
        
    }

    int ans = INT_MAX;

    for(int i = 1; i <= n; i++) {
        int xx = ara[i];
        for(int j = i + 1; j <= n; j++) {
            int yy = ara[j];
            for(int k = j + 1; k <= n; k++) {
                // cout << i << " " << j << " " << k << " " << " : " << xx << " " << yy << endl;
                if(xx > yy) {
                    ans = min(ans, j - i - 1 + k - j - 1);
                }
                yy ^= ara[k];
            }
            if(xx > yy) {
                ans = min(ans, j - i - 1 + (n + 1) - j - 1);
            }
            xx ^= ara[j];
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;

    return 0;
}
/**
 * 
*/
