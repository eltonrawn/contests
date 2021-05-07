#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        int n, up, right, down, left;
        cin >> n >> up >> right >> down >> left;
        bool chk = 0;
        for(int a = 0; a <= 1; a++) {
            for(int b = 0; b <= 1; b++) {
                for(int c = 0; c <= 1; c++) {
                    for(int d = 0; d <= 1; d++) {
                        if(up - a - b >= 0 && up - a - b <= n - 2) {
                            if(right - b - c >= 0 && right - b - c <= n - 2) {
                                if(down - c - d >= 0 && down - c - d <= n - 2) {
                                    if(left - d - a >= 0 && left - d - a <= n - 2) {
                                        chk = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ((chk == 1) ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
 * 
 * another solution maybe:
 * upper-left = a
 * upper-right = b
 * down-right = c
 * down-left = d
 * 
 * 0 <= uu, rr, dd, ll <= n - 2
 * 0 <= a, b, c, d <= 1
 * 
 * up = uu + a + b
 * right = rr + b + c
 * down = dd + c + d;
 * left = ll + d + a
 * 
*/
