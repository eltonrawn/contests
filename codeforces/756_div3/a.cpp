#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        string str;
        cin >> str;
        if((str.back() - '0') % 2 == 0) {
            cout << 0 << endl;
            continue;
        }
        if((str[0] - '0') % 2 == 0) {
            cout << 1 << endl;
            continue;
        }
        int ans = -1;
        for(char ch: str) {
            if((ch - '0') % 2 == 0) {
                ans = 2;
                break;
            }
        }
        cout << ans << endl;

    }
    return 0;
}
/**
*/
