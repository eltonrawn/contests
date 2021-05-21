#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
int n, k;
int ara[SZ];
bool vis[SZ][3];
LL dp[SZ][3];
 
LL func(int pos, int steps) {
    LL cc = INT_MIN;
    if(steps >= 2) {
        cc = 0;
    }
    if(pos > n) {
        return cc;
    }
    if(vis[pos][steps]) {
        return dp[pos][steps];
    }
    LL ans = INT_MIN;
    if(ara[pos] >= k) {
        ans = 1 + max(cc, func(pos + 1, min(2, steps + 1)));
    }
    else {
        ans = -1 + max(cc, func(pos + 1, min(2, steps + 1)));
    }
    vis[pos][steps] = 1;
    return dp[pos][steps] = ans;
}
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        bool chk = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            if(ara[i] == k) chk = 1;
        }
        if(!chk) {
            cout << "no" << endl;
            continue;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                vis[i][j] = 0;
            }            
        }
        chk = 0;
        for(int i = 1; i <= n; i++) {
            chk = max(chk, (func(i, 0) > 0 ? true : false));
        }
 
        if(chk || n == 1) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}
/**
*/