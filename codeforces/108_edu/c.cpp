#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int u[SZ], skill[SZ];

vector<LL> univ[SZ], csum[SZ];
set<PLL> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            univ[i].clear();
            csum[i].clear();
        }
        st.clear();

        for(int i = 1; i <= n; i++) {
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> skill[i];
        }
        for(int i = 1; i <= n; i++) {
            univ[u[i]].push_back(skill[i]);
        }
        for(int i = 1; i <= n; i++) {
            sort(univ[i].begin(), univ[i].end(), greater<int>());
            LL sum = 0;
            for(int j = 0; j < univ[i].size(); j++) {
                sum += univ[i][j];
                csum[i].push_back(sum);
            }
            st.insert({univ[i].size(), i});
        }

        for(int k = 1; k <= n; k++) {
            while(!st.empty() && (*st.begin()).first < k) {
                st.erase(st.begin());
            }
            LL ans = 0;
            for(PII pr: st) {
                int pos = pr.second;
                int vag = univ[pos].size() / k;
                ans += csum[pos][(vag * k) - 1];
            }
            cout << ans << " ";
        }
        cout << endl;

    }
    return 0;
}
/**
*/
