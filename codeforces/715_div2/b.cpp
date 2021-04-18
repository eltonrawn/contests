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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string s;
bool taken[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> s;

        FOR(i, 0, n - 1) {
            taken[i] = 0;
        }
        bool chk = 1;

        for(int i = 0, j = 0; i < n; i++) {
            if(s[i] == 'M') {
                
                while(j < n && (s[j] != 'T' || taken[j] == 1)) {
                    j++;
                }
                if(j > i) {
                    chk = 0;
                    break;
                }
                // cout << "hi1 " << i << " " << j << "\n";
                taken[j] = 1;
                j++;
                continue;
            }
        }

        for(int i = n - 1, j = n - 1; i >= 0; i--) {
            if(s[i] == 'M') {
                while(j >= 0 && (s[j] != 'T' || taken[j] == 1)) {
                    j--;
                }
                if(j < i) {
                    chk = 0;
                    break;
                }
                // cout << "hi2 " << i << " " << j << "\n";
                taken[j] = 1;
                j--;
                continue;
            }
        }
        FOR(i, 0, n - 1) {
            if(s[i] == 'T' && taken[i] == 0) {
                chk = 0;
                break;
            }
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
