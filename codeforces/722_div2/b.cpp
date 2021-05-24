#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            if(ara[i] <= 0) ans++;
        }
        sort(ara + 1, ara + n + 1);
        int st = 0;
        for(int i = 1; i <= n; i++) {
            if(ara[i] > 0) {
                st = i;break;
            }
        }
        if(st == 0) {
            cout << ans << endl;
            continue;
        }

        int last = ara[st];
        int tmp = 1;
        // cout << ara[st] << " ";
        for(int i = st - 1; i >= 1; i--) {
            if(last - ara[i] >= ara[st]) {
                // cout << ara[i] << " ";
                tmp++; last = ara[i];
            }
        }
        // cout << endl;
        ans = max(ans, tmp);
        
        cout << ans << endl;
    }
    return 0;
}
/**
*/
