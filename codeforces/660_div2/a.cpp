#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        vector<int> vv = {6, 10, 14, 15};
        int n;
        cin >> n;
        if(n <= 30) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(n - 30 != 6 && n - 30 != 10 && n - 30 != 14) {
            cout << 6 << " " << 10 << " " << 14 << " " << n - 30 << endl;
            continue;
        }
        cout << 6 << " " << 10 << " " << 15 << " " << n - 31 << endl;
    }
    return 0;
}
/**
*/
