#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
// map<int, int> taken;
bool is_val(int le, int ri) {
    for(int i = le; i <= ri; i++) {
        for(int j = i + 1; j <= ri; j++) {
            for(int k = j + 1; k <= ri; k++) {
                // (i, k) == (i, j) + (j, k)
                LL fir = abs(ara[i] - ara[k]) + abs(i - k);
                LL sec = abs(ara[i] - ara[j]) + abs(i - j) + abs(ara[j] - ara[k]) + abs(j - k);
                if(fir == sec) return 0;
            }
        }
    }
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= min(i + 5, n); j++) {
                ans += is_val(i, j);
            }
        }
        cout << ans << endl;
        // taken.clear();
        // LL ans = 0;
        // LL le = 1, ri;
        // for(ri = 1; ri <= n; ri++) {
        //     taken[ara[ri]]++;
        //     while((le < ri) && taken[ara[ri]] > 1) {
        //         ans += ri - le;
        //         taken[ara[le]]--;
        //         if(ara[le] == ara[ri]) ans++;
        //         le++;
        //     }
        // }
        // LL len = ri - le;
        // ans += (len * (len + 1LL)) / 2LL;
        // cout << le << " " << ri << endl;
        // cout << ans << endl;

    }
    return 0;
}
/**
*/
