#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
vector<int> dp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> ara[i];
    
    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), ara[i]) - dp.begin();
        if(pos == dp.size())
            dp.push_back(ara[i]);
        else
            dp[pos] = ara[i];
    }
    cout << dp.size() << endl;
    return 0;
}
/**
*/
