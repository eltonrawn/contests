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
vector<int> even, odd, allv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        even.clear(); odd.clear(); allv.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            if(ara[i] % 2) odd.push_back(ara[i]);
            else even.push_back(ara[i]);
        }
        for(int val: even) {
            allv.push_back(val);
        }
        for(int val: odd) {
            allv.push_back(val);
        }
        // for(int val: allv) {
        //     cout << val << " ";
        // }
        // cout << endl;
        int ans = 0;
        for(int i = 0; i < allv.size(); i++) {
            for(int j = i + 1; j < allv.size(); j++) {
                if(__gcd(allv[i], 2 * allv[j]) > 1) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
