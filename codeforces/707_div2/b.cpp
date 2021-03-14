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
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[MX];
bool ans[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            cin >> ara[i];
            ans[i] = 0;
        }
        int cr = 0;
        ROF(i, n, 1) {
            cr = max(cr, ara[i]);
            if(cr) {
                ans[i] = 1;
                cr--;
            }
        }
        FOR(i, 1, n) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
 * 5200000
 * 5.2 * 10^6
*/
