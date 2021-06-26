#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];

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
        LL ans = 0;

        for(LL i = 2; i <= n; i++) {
            // int gun = ara[i];
            LL rem = ((i + 1) / ara[i]);
            LL start = ara[i] * rem;
            if(start < i + 1) {
                start += ara[i];
            }

            // for(LL kk = start, j = start - i; kk <= i + i - 1; kk += ara[i], j += ara[i]) {
            for(LL j = start - i; j < i; j += ara[i]) {
                if(ara[i] * ara[j] == i + j)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
