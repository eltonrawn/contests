#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
int n;
int ara[SZ], lastpos[SZ], cnt[SZ];
 
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
            lastpos[i] = cnt[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            if(i - lastpos[ ara[i] ] > 1) cnt[ara[i]]++;
            lastpos[ara[i]] = i;
        }
        for(int i = 1; i <= n; i++) {
            if(i != ara[n]) {
                cnt[i]++;
            }
        }
        int mn = INT_MAX;
        for(int i = 1; i <= n; i++) {
            mn = min(mn, cnt[ara[i]]);
        }
        cout << mn << endl;
    }
    return 0;
}
/**
*/