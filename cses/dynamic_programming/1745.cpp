#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 110
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int coins[SZ];
int dp[100010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int total = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> coins[i];
        total += coins[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = total; j >= 1; j--) {
            if(j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];
        }
    }

    vector<int> ans;

    for(int i = 1; i <= total; i++) {
        if(dp[i])
            ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(int val: ans)
        cout << val << " ";
    cout << endl;
    return 0;
}
/**
*/
