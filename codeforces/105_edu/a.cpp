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

string str;

int func(int pos, int le, int a, int b, int c) {
    if(pos == str.size()) {
        if(le) {
            return 0;
        }
        return 1;
    }
    int use = 0;
    if(str[pos] == 'A') {
        use = a;
    }
    else if(str[pos] == 'B') {
        use = b;
    }
    else {
        use = c;
    }
    int ans = 0;

    if(use) {
        /// place "("
        ans = func(pos + 1, le + 1, a, b, c);
    }
    else {
        /// place ")"
        if(le) {
            ans = func(pos + 1, le - 1, a, b, c);
        }
        
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> str;
        int ans = 0;
        FOR(a, 0, 1) {
            FOR(b, 0, 1) {
                FOR(c, 0, 1) {
                    ans = max(ans, func(0, 0, a, b, c));
                }
            }
        }
        cout << (ans == 0 ? "NO" : "YES") << endl;
    }
    return 0;
}
/**
*/
