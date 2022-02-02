#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
pair<int, pair<int, int> > pr[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int x, y, s;
            cin >> x >> y >> s;
            pr[i] = {x, {y, s}};
        }
        sort(pr + 1, pr + 1 + n);
        set< pair<int, int> > st;
        LL cnt = 0;
        LL ans = 0;
        for(int i = n; i >= 1; i--) {
            while(!st.empty()) {
                if((*(--st.end())).first > pr[i].first) {
                    cnt -= (*(--st.end())).second;
                    if(cnt < 0) cnt += MOD;
                    st.erase(--st.end());
                }
                else break;
            }
            LL ff = cnt;
            if(pr[i].second.second) ff++;
            if(ff >= MOD) ff -= MOD;

            ans += ff * (pr[i].first - pr[i].second.first); ans %= MOD;
            
            cnt += ff;
            if(cnt >= MOD) cnt -= MOD;

            st.insert({pr[i].second.first, ff});
        }
        ans += pr[n].first + 1;
        if(ans >= MOD) ans -= MOD;
        cout << ans << endl;
    // }
    return 0;
}
/**
*/
