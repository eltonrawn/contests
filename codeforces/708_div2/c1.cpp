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

int n, k;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        if(n % 2) {
            cout << (n - 1) / 2 << " " << (n - 1) / 2 << " " << 1 << "\n";
        }
        else if((n / 2) % 2) {
            cout << (n - 2) / 2 << " " << (n - 2) / 2 << " " << 2 << "\n";
        }
        else {
            cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
        }

    }
    return 0;
}
/**
*/
