#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str;
map<int, int> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> str;
        mp.clear();
        bool chk = 1;
        for(int i = 1; i <= str.size(); i++) {
            if(mp[str[i - 1]] != 0 && mp[str[i - 1]] != i - 1) {
                chk = 0;
                break;
            }
            mp[str[i - 1]] = i;
        }
        cout << ((chk == 1) ? "YES": "NO") << endl;
    }
    return 0;
}
/**
*/
