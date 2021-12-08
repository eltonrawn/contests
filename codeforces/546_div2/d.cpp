#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int per[SZ];
set<PII> st;
map< PII, bool > mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> per[i];
            st.insert({i, per[i]});
        }
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            mp[{u, v}] = 1;
        }
        int ans = 0;
        for(int i = n - 1; i >= 1; i--) {
            if(mp[{per[i], per[n]}] == 0) {
                /// this won't pass me anyway
                continue;
            }
            auto it = st.find({i, per[i]});
            it++;
            bool chk = 1;
            while(it != st.end()) {
                if(mp[{per[i], it->second}]) {
                    it++;
                    continue;
                }
                chk = 0; break;
            }
            if(chk) {
                ans++;
                st.erase({i, per[i]});
            }
        }
        cout << ans << endl;
    // }
    return 0;
}
/**
start: 6:08 pm
end: 6:29 pm
duration: 21 mins
*/
