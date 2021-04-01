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
int ara[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 0, n - 1) {
            cin >> ara[i];
        }
        // if(n <= 2) {
        //     cout << 0 << "\n";
        //     continue;
        // }
        vector<int> foo;
        FOR(i, 1, n - 1) {
            foo.push_back(ara[i] - ara[i - 1]);
        }
        sort(foo.begin(), foo.end());
        foo.erase(unique(foo.begin(), foo.end()), foo.end());
        if(foo.size() <= 1) {
            cout << 0 << "\n";
            continue;
        }

        int c = -1;
        bool chk = 1;
        FOR(i, 1, n - 1) {
            if(ara[i - 1] <= ara[i]) {
                c = ara[i] - ara[i - 1];
            }
            if(ara[i - 1] > ara[i]) {
                chk = 0;
            }
        }
        if(c == -1) {
            /// only decreasing but interval is not same
            cout << -1 << "\n";
            continue;
        }
        if(chk) {
            /// only increasing but interval is not same
            cout << -1 << "\n";
            continue;
        }

        /// both increasing and decreasing
        
        int m = -1;
        FOR(i, 1, n - 1) {
            if(ara[i - 1] > ara[i]) {
                m = ara[i - 1] + (c - ara[i]);
                break;
            }
        }
        if(m <= 0 || c >= m || ara[0] >= m) {
            cout << -1 << "\n";
            continue;
        }

        chk = 1;

        FOR(i, 1, n - 1) {
            int tmp = (ara[i - 1] + c) % m;
            if(tmp != ara[i]) {
                chk = 0;
                break;
            }
        }

        if(chk) {
            cout << m << " " << c << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
/**
*/
