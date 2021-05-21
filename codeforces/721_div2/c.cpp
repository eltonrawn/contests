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
map<int, LL> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        mp.clear();
        cin >> n;
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            ans += mp[ara[i]] * (n - i + 1LL);
            mp[ara[i]] += i;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
