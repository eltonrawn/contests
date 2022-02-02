#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
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
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        int lim = n;
        for(int i = lim - 1; i >= 1; i--) {
            if(ara[i] < ara[i + 1]) {
                break;
            }
            lim = i;
        }
        if(lim != 1) lim--;
        for(int i = lim - 1; i >= 1; i--) {
            if(ara[i] > ara[i + 1]) {
                break;
            }
            lim = i;
        }
        cout << lim - 1 << endl;
    }
    return 0;
}
/**
*/
