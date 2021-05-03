#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m, x;
PLL h[SZ];
set<PLL> st;
int ans[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m >> x;
        for(int i = 1; i <= n; i++) {
            cin >> h[i].first;
            h[i].second = i;
        }
        sort(h + 1, h + n + 1);
        st.clear();
        for(int i = 1; i <= m; i++) {
            st.insert({0, i});
        }
        for(int i = 1; i <= n; i++) {
            PLL pr = *st.begin();
            st.erase(st.begin());
            LL val = pr.first; int pos = pr.second;
            ans[ h[i].second ] = pos;
            st.insert({val + h[i].first, pos});
        }
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
