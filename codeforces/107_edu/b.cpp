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

int a, b, c;

int get_len(int tmp) {
    int cnt = 0;
    while(tmp) {
        cnt++;
        tmp /= 10;
    }
    return cnt;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> a >> b >> c;
        LL cc = 1;
        FOR(i, 1, c - 1) {
            cc *= 10;
        }
        // cout << "cc : " << cc << endl;
        // return 0;
        LL aa = cc;
        for(;;) {
            // cout << "aa : " << aa << endl;
            if(get_len(aa) == a) {
                break;
            }
            aa *= 3;
        }
        
        LL bb = cc;
        for(;;) {
            if(get_len(bb) == b) {
                break;
            }
            bb *= 7;
        }
        // cout << (__gcd(aa, bb) == cc) << " " << cc << endl;

        cout << aa << " " << bb << endl;
    }
    return 0;
}
/**
*/
