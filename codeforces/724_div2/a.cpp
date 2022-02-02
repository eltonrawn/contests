#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            mn = min(mn, ara[i]);
            mx = max(mx, ara[i]);
        }
        if(mn < 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << mx + 1 << endl;
        for(int i = 0; i <= mx; i++) {
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}
/**
*/
