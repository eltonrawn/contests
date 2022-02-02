#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ], vis[SZ];
vector<int> ans;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n * 2; i++) {
            cin >> ara[i];
            vis[i] = 0;
        }
        ans.clear();
        for(int i = 1; i <= n * 2; i++) {
            if(vis[ara[i]]) {
                continue;
            }
            vis[ara[i]] = 1;
            ans.push_back(ara[i]);
        }
        for(int val: ans) {
            cout << val << " ";
        }
        cout << endl;

    }
    return 0;
}
/**
*/
