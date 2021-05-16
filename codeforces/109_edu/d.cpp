#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 5010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
vector<int> yoyo;
LL inf = 10000000000000000LL;

LL dp[SZ][SZ];

LL func(int pos, int p1) {
    if(p1 == yoyo.size()) {
        return 0;
    }
    if(pos == n) {
        return inf;
    }
    if(dp[pos][p1] != -1) {
        return dp[pos][p1];
    }
    if(ara[pos] == 1) {
        return func(pos + 1, p1);
    }
    LL ans = inf;
    /// not assigning
    ans = min(ans, func(pos + 1, p1));
    
    /// assigning p1 to this pos
    ans = min(ans, (LL)abs(pos - yoyo[p1]) + func(pos + 1, p1 + 1));
    return dp[pos][p1] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
        if(ara[i]) {
            yoyo.push_back(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << func(0, 0) << endl;;
    return 0;
}
/**
*/
