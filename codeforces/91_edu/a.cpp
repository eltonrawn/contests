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
map<int, int> pos;
int mna[SZ], mxa[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        pos.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            pos[ara[i]] = i;
        }
        mna[0] = INT_MAX;
        for(int i = 1; i <= n; i++) {
            mna[i] = min(ara[i], mna[i - 1]);
        }

        mxa[n + 1] = INT_MAX;
        for(int i = n; i >= 1; i--) {
            mxa[i] = min(ara[i], mxa[i + 1]);
        }
        bool chk = 0;
        for(int i = 2; i <= n - 1; i++) {
            // cout << mna[i - 1] << " " << ara[i] << " " << mxa[i + 1] << endl;
            if(ara[i] > mna[i - 1] && ara[i] > mxa[i + 1]) {
                cout << "YES" << endl;
                cout << pos[mna[i - 1]] << " " << i << " " << pos[mxa[i + 1]] << endl;
                chk = 1; break;
            }
        }
        if(!chk) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
/**
*/
