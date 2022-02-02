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
vector<int> ans;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        ans.clear();
        ans.push_back(ara[1]);
        int cnt = 0;
        for(int i = 2; i <= n; i++) {
            int mn = min(ara[i], ara[i - 1]);
            int mx = max(ara[i], ara[i - 1]);
            while(mn * 2 < mx) {
                // cout << mn * 2 << " ";
                ans.push_back(mn * 2); cnt++;
                mn = mn * 2;
            }
            ans.push_back(ara[i]);
        }
        cout << cnt << endl;
    }
    return 0;
}
/**
*/
