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

int n, w1, w2, b1, b2, w, b;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> w1 >> w2;
        cin >> w >> b;
        b1 = n - w1;
        b2 = n - w2;
        bool y1 = 0, y2 = 0;
        FOR(i, 0, min(w1, w2)) {
            int taken = i;
            taken += (w1 - i) / 2;
            taken += (w2 - i) / 2;
            if(taken >= w) {
                y1 = 1;
                break;
            }
        }

        FOR(i, 0, min(b1, b2)) {
            int taken = i;
            taken += (b1 - i) / 2;
            taken += (b2 - i) / 2;
            if(taken >= b) {
                y2 = 1;
                break;
            }
        }

        if(y1 && y2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
/**
*/
