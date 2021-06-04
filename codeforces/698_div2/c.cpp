#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n;
LL ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= 2 * n; i++) {
            cin >> ara[i];
        }
        sort(ara + 1, ara + 1 + (2 * n));
        bool chk = 1;
        for(int i = 1; i <= 2 * n; i += 2) {
            if(ara[i] != ara[i + 1]) {
                chk = 0;
                break;
            }
        }
        LL cnt = 0;
        LL csum = 0;
        vector<LL> vv;
        for(int i = 2 * n; i >= 1 && chk; i -= 2) {

            // cout << ara[i] << " : " << ((ara[i] - csum) % (n - cnt)) << endl;
            if(ara[i] <= csum || (ara[i] - csum) % (n - cnt)) {
                chk = 0;
                break;
            }
            if(((ara[i] - csum) / (n - cnt)) % 2) {
                chk = 0;
                break;
            }
            LL val = ((ara[i] - csum) / (n - cnt)) / 2;
            if(val == 0) {
                chk = 0; break;
            }
            // cout << "val " << " : " << ((ara[i] - csum) / (n - cnt)) << endl;
            vv.push_back(val);
            csum += ((ara[i] - csum) / (n - cnt));
            cnt++;
            // cout << ara[i] << " >= " << gun * cnt << "; val = " << (ara[i] - (gun * cnt)) << endl;
            // if(ara[i] < gun * cnt) {
            //     chk = 0; break;
            // }
        }
        for(int i = 1; i < vv.size() && chk; i++) {
            // cout << vv[i] << " ";
            if(vv[i] >= vv[i - 1]) {
                chk = 0; break;
            }
        }
        // cout << endl;
        cout << (chk == 0? "NO" : "YES") << endl;
    }
    return 0;
}
/**
*/
