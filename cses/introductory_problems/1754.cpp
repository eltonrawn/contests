#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int a, b;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        int x, y; cin >> x >> y;
        a = min(x, y); b = max(x, y);

        int lo = 0, hi = a;
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int taken = a - mid;
            if(mid + taken * 2 < b) {
                hi = mid - 1;
            }
            else {
                lo = mid;
            }
        }
        // cout << "lo " << lo << endl;
        int taken = a - lo;
        a -= taken;
        b -= taken * 2;
        if(a != b || a % 3) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
/**
*/
