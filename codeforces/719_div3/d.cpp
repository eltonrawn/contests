#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 400010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
map<int, int> mp;
vector<int> vv[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        mp.clear();
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            mp[ ara[i] - i ]++;
        }
        LL ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            LL cnt = it->second;
            ans += (cnt * (cnt - 1)) / 2;
        }
        cout << ans << endl;

    }
    return 0;
}
/**
*/
