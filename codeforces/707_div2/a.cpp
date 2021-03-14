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
int a[110], b[110], tmm[110];

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
            cin >> a[i] >> b[i];
        }
        FOR(i, 1, n) {
            cin >> tmm[i];
        }
        int cur = 0;
        FOR(i, 1, n) {
            if(i < n) {
                cur += (a[i] - b[i - 1]) + tmm[i] + (b[i] - a[i] + 1) / 2;
                cur = max(cur, b[i]);
            }
             else {
                 cur += (a[i] - b[i - 1]) + tmm[i];
             }
            // cout << "cur : " << cur << endl;
        }
        cout << cur << endl;
    }
    return 0;
}
/**
*/
