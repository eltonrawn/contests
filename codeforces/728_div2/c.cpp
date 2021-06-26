#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];
vector<LL> vv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        vv.clear();
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            if(ara[i] >= 0)
                vv.push_back(ara[i]);
            else
                ans += ara[i];
        }
        
        sort(vv.begin(), vv.end());
        
        LL csum = 0;
        LL cnt = 0;
        for(int i = 1; i < vv.size(); i++) {
            cnt = i;
            LL diff = vv[i] - vv[i - 1];
            ans -= csum + ((cnt - 1) * diff);
            csum += cnt * diff;
            // cout << csum << " " << ans << endl;
        }
        cout << ans << endl;

        // cout << endl;
    }
    return 0;
}
/**
*/
