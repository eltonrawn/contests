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

string a, b;
int dp[21][21][21][21];

bool is_same_yo(int a1, int a2, int b1, int b2) {
    if(a2 - a1 != b2 - b1) {
        return 0;
    }
    for(int i = a1, j = b1; i <= a2; i++, j++) {
        if(a[i] != b[j]) {
            return 0;
        }
    }
    return 1;
}

int func(int a1, int a2, int b1, int b2) {
    int ans = 1000000;
    if(a1 <= a2 && b1 <= b2) {
    }
    else {
        return ans;
    }
    if(dp[a1][a2][b1][b2] != -1) {
        return dp[a1][a2][b1][b2];
    }
    if(is_same_yo(a1, a2, b1, b2)) {
        ans = 0;
        // cout << "hi\n";
    }
    else {
        ans = min(ans, 1 + func(a1 + 1, a2, b1, b2));
        ans = min(ans, 1 + func(a1, a2 - 1, b1, b2));
        ans = min(ans, 1 + func(a1, a2, b1 + 1, b2));
        ans = min(ans, 1 + func(a1, a2, b1, b2 - 1));
    }
    
    
    // cout << a1 << " " << a2 << " " << b1 << " " << b2 << " : " << ans << endl;
    return dp[a1][a2][b1][b2] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        MEM(dp, -1);
        cin >> a >> b;
        int ans = a.size() + b.size();
        ans = min(ans, func(0, a.size() - 1, 0, b.size() - 1));
        cout << ans << endl;
    }
    return 0;
}
/**
 * 320000000
*/
