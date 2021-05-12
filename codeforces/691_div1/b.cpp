#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector< PII > v;
int dp[110][10010];
vector<double> ans;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    v.resize(n + 2);
    ans.resize(n + 2, INT_MIN);
    int tot_a = 0, tot_b = 0;
    for(int i = 1; i <= n; i++) {
        int fir, sec;
        cin >> fir >> sec;
        v[i] = {fir, sec};
        tot_a += fir;
        tot_b += sec;
    }
    for(int k = 0; k <= n; k++) {
        for(int a = 0; a <= tot_a; a++) {
            dp[k][a] = INT_MIN;
        }
    }
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int k = n; k >= 0; k--) {
            for(int a = 0; a <= tot_a; a++) {
                /// don't take it

                /// take it
                if(a - v[i].first >= 0 && k - 1 >= 0)
                    dp[k][a] = max(dp[k][a], v[i].second + dp[k - 1][a - v[i].first]);
                ans[k] = max(ans[k], min((double)a, dp[k][a] / 2.0 + tot_b / 2.0));

                // if(k != 1) continue;
                // cout << i << " " << k << " " << a << " : " << min((double)a, dp[i][k][a] / 2.0 + tot_b / 2.0) << endl;
            }
        }
    }

    for(int k = 1; k <= n; k++) {
        cout << fixed << setprecision(9) << ans[k] << " ";
    }
    cout << endl;



    return 0;
}
/**
 * 
 * tags: iterative dp
 * 
 * after selecting k glasses, 
 * total capacity of those k glasses: A
 * total contained water of these k glasses: bk
 * 
 * total contained water of all glasses: b
 * 
 * min(A, bk + ((b - bk) / 2))
 * min(A, bk + b / 2 - bk / 2))
 * min(A, bk / 2 + b / 2))
 * 
 * dp[i][k][A] --> max bk
*/
