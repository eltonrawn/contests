#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
pair<LL, LL> ab[SZ];
LL a[SZ], b[SZ];
LL csum[SZ];
map<LL, LL> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        mp.clear();
        for(int i = 1; i <= m; i++) {
            cin >> a[i] >> b[i];
            mp[b[i]] = max(mp[b[i]], a[i]);
            ab[i] = {a[i], b[i]};
        }
        sort(ab + 1, ab + m + 1, greater<pair<int, int>>());

        for(int i = 1; i <= m; i++) {
            csum[i] = ab[i].first + csum[i - 1];
        }

        LL ans = 0;

        for(auto it: mp) {
            LL bb = it.first;
            LL aa = it.second;
            int lo = 1, hi = m;
            while(lo < hi) {
                int mid = lo + (hi - lo + 1) / 2;
                if(ab[mid].first < bb) {
                    hi = mid - 1;
                }
                else {
                    lo = mid;
                }
            }

            if(ab[lo].first >= bb) {
                lo = min(lo, n);
                if(aa >= ab[lo].first) {
                    ans = max(ans, csum[lo] + (LL)bb * (n - lo));
                    continue;
                }

                ans = max(ans, csum[lo - 1] + aa + (LL)bb * max(0LL, (LL)(n - lo)));

                if(lo + 1 <= n) {
                    ans = max(ans, csum[lo] + aa + (LL)bb * (n - 1 - lo));
                }
                continue;
            }
            ans = max(ans, aa + (LL)bb * (n - 1LL));
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
