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
vector<PII> vv;
int r[MX], c[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        vv.clear();
        cin >> n;
        FOR(i, 1, n) {
            cin >> r[i];
        }
        FOR(i, 1, n) {
            cin >> c[i];
            vv.PB({r[i], c[i]});
        }
        sort(vv.begin(), vv.end());
        LL x = 1, y = 1;
        LL ans = 0;
        for(PII nxy: vv) {
            LL nx = nxy.F;
            LL ny = nxy.S;
            
            if(((nx - ny + 1) == (x - y + 1)) && ((x - y + 1 + 1) % 2 == 0)) {
                ans += ny - y;
            }
            else if((x + y) % 2) {
                /// odd
                ans += ((nx - ny + 1) - (x - y + 1) + 1) / 2;
            }
            else {
                /// even
                ans += ((nx - ny + 1) - (x - y + 1)) / 2;
            }
            x = nx;
            y = ny;
            // cout << nx << " " << ny << " : " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
