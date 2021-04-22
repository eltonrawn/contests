#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[2010], xray[2010];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            xray[i] = ara[i] ^ xray[i - 1];
        }
        
        if(xray[n] == 0) {
            cout << "YES" << endl;
            continue;
        }

        LL xx = 0;
        bool chk = 0;
        bool is_zero = 0;
        for(int i = n; i >= 1; i--) {
            if(xray[i] == 0) {
                is_zero = 1;
            }
            if(is_zero == 0) {
                continue;
            }
            if(xray[i] == xray[n]) {
                chk = 1;
                break;
            }
        }

        cout << (chk == 1? "YES": "NO") << endl;
    }
    return 0;
}
/**
*/
