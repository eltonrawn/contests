#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, u, v;
int ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> u >> v;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }

        int max_gap = 0;
        for(int i = 2; i <= n; i++) {
            max_gap = max(max_gap, abs(ara[i] - ara[i - 1]));
        }
        if(max_gap == 0)
            cout << min(u + v, 2 * v) << endl;
        else if(max_gap == 1)
            cout << min(u, v) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
/**
*/
