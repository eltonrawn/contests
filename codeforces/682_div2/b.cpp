#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int a[SZ];
map<int, int> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        mp.clear();
        bool chk = 0;
        for(int i = 1; i <= n; i++) {
            if(mp[a[i]]) {
                chk = 1;
                break;
            }
            mp[a[i]] = i;
        }
        cout << ((chk == 1)? "YES": "NO") << endl;
    }
    return 0;
}
/**
*/
