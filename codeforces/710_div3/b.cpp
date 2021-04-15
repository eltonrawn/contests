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
string s;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        cin >> s;
        LL cnt = 0;
        // int last = -1;
        // ROF(i, (int)s.size() - 1, 0) {
        //     if(s[i] == '*') {
        //         // cnt++;
        //         // s[i] = 'X';
        //         last = i;
        //         break;
        //     }
        // }
        int fir = 0;
        FOR(i, 0, (int)s.size() - 1) {
            if(s[i] == '*') {
                fir = i;
                break;
            }
        }
        cnt = 1;
        // cout << "fir : " << fir << endl;
        for(int i = fir; i < s.size(); i++) {
            for(int j = min(i + k, (int)s.size() - 1); j > i; j--) {
                if(s[j] == '*') {
                    // cout << j << " ";
                    cnt++;
                    i = j - 1;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
/**
*/
