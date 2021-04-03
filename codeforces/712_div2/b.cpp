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
string a, b;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> a >> b;

        bool chk = 1;
        for(int i = 0; i < n; i++) {
            int j;
            int one = 0;
            for(j = i; j < n; j++) {
                if(a[j] == '1') {
                    one++;
                }
                else {
                    one--;
                }
                if(one == 0) {
                    break;
                }
            }
            if(one) {
                /// means j = n
                for(int k = i; k < n; k++) {
                    if(a[k] != b[k]) {
                        chk = 0;
                        // cout << "hi1 " << i << " " << j << " " << k << endl;
                        break;
                    }
                }
                break;
            }
            bool same = 0;
            bool diff = 0;
            for(int k = i; k <= j; k++) {
                if(a[k] != b[k]) {
                    diff = 1;
                }
                else {
                    same = 1;
                }
            }
            if(same && diff) {
                // cout << "hi2 " << i << " " << j << endl;
                chk = 0;
                break;
            }
            i = j;
        }
        if(chk) {
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
