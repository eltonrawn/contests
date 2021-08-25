#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 7; j >= 0; j--) {
        //         if(ara[i] & (1 << j))
        //             cout << 1;
        //         else
        //             cout << 0;
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        cout << 0 << " ";
        LL past = ara[0];
        for(int i = 1; i < n; i++) {
            past |= ara[i];

            cout << (past ^ ara[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
