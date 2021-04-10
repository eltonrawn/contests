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
LL c;
LL a[MX], b[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> c;
        FOR(i, 1, n) {
            cin >> a[i];
        }
        FOR(i, 1, n - 1) {
            cin >> b[i];
        }
        LL res_days = LLONG_MAX;

        LL days = 0;
        LL got = 0;
        FOR(i, 1, n) {
            
            if(got >= c) {
                res_days = min(res_days, days);
                break;
            }

            LL cc = ((c - got) / a[i]);
            if((c - got) % a[i]) {
                cc++;
            }
            res_days = min(res_days, days + cc);
            // cout << i << " : " << days + cc << endl;
            if(i == n) {
                break;
            }

            if(b[i] > got) {
                LL tmp = (b[i] - got) / a[i];
                if((b[i] - got) % a[i]) {
                    tmp++;
                }
                days += tmp;
                got += (tmp * a[i]);
            }

            /// extra days for moving up
            days++;
            got -= b[i];
            
        }
        cout << res_days << "\n";
    }
    return 0;
}
/**
*/
