#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, a, b;
map<int, int> mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> a >> b;
        // for(int i = 1; i <= 200; i++) {
        //     if((i - 1) % b == 0) cout << endl;
        //     cout << setw(3) << i << " ";
        // }
        // cout << endl;
        mp.clear();
        mp[1 % b] = 1;
        LL make = 1 * a;
        while(make <= n) {
            if(mp[make % b]) break;
            mp[make % b] = make;
            make *= a;
        }
        if(mp[n % b] == 0 || mp[n % b] > n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
/**
*/
