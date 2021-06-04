#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, ans;
int ara[110], vis[110];

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
            vis[i] = 0;
        }
        ans = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            // cout << "i : " << i << endl;
            vis[i] = 1;
            ans++;
            int past = ara[i];
            for(int j = i + 1; j <= n; j++) {
                if(!vis[j] && ara[j] > past) {
                    vis[j] = 1;
                    past = ara[j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
