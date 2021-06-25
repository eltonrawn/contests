#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL solve(LL x, LL y) {
    if(x > y) {
        LL used = (x - 1) * (x - 1);
        if(x % 2) {
            return used + y;
        }
        else {
            return used + (x - 1) + (x - y + 1);
        }
    }
    else {
        LL used = (y - 1) * (y - 1);
        if(y % 2 == 0) {
            return used + x;
        }
        else {
            return used + (y - 1) + (y - x + 1);
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // for(int x = 1; x <= 9; x++) {
    //     for(int y = 1; y <= 9; y++) {
    //         cout << solve(x, y) << "   ";
    //     }
    //     cout << endl;
    // }
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        LL x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
/**
*/
