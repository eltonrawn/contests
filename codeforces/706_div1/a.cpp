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

int n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    // cout << sqrt((3 * 3) + (3 * 3)) + sqrt((4 * 4) + (4 * 4)) << endl;
    // cout << sqrt((3 * 3) + (4 * 4)) + sqrt((4 * 4) + (3 * 3)) << endl;
    // sqrt(18) + sqrt(32);
    // sqrt(25) + sqrt(25);

    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        vector<LL> a, b;
        FOR(i, 1, n * 2) {
            LL x, y;
            cin >> x >> y;
            if(x == 0) {
                a.PB(y * y);
            }
            else {
                b.PB(x * x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double ans = 0;
        for(int i = 0; i < n; i++) {
            ans += sqrt(a[i] + b[i]);
        }
        cout << fixed << setprecision(15) << ans << "\n";
    }
    return 0;
}
/**
 * 3.650281539872885
*/
