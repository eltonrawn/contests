#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int sz, n;
int pos[SZ];
LL temp[SZ];
LL ans[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> sz >> n;
        for(int i = 1; i <= sz; i++) {
            temp[i] = 0;
            ans[i] = 1000000000000000LL;
        }
        for(int i = 1; i <= n; i++) {
            cin >> pos[i];
        }
        for(int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            temp[ pos[i] ] = tmp;
        }
        
        LL tmp = 1000000000000000LL;
        for(int i = 1; i <= sz; i++) {
            tmp++;
            if(temp[i]) {
                tmp = min(tmp, temp[i]);
            }
            ans[i] = min(ans[i], tmp);
        }

        tmp = 1000000000000000LL;
        for(int i = sz; i >= 1; i--) {
            tmp++;
            if(temp[i]) {
                tmp = min(tmp, temp[i]);
            }
            ans[i] = min(ans[i], tmp);
        }
        for(int i = 1; i <= sz; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
/**
*/
