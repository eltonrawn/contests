#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL x;

bool is_sqrt(LL nn) {
    if(nn <= 0) return 0;
    LL lo = 1, hi = min(nn, 20000LL);
    while(lo < hi) {
        LL mid = lo + (hi - lo + 1) / 2;
        // cout << "mid " << mid << endl;
        if(mid * mid * mid <= nn) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    if(lo * lo * lo == nn) {
        return 1;
    }
    return 0;

}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> x;
        bool chk = 0;
        for(LL i = 1; i <= min(20000LL, x); i++) {
            LL a = i * i * i;
            if(a > x) {
                break;
            }
            
            LL nn = x - a;

            if(is_sqrt(nn)) {
                chk = 1; break;
            }
        }
        cout << (chk == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
 * 7 03657519796
*/
