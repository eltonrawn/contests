#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int b[110][110], c[110][110];
vector<PII> yo[110];
set< pair<int, pair<int, int> > > st;
multiset<int> vals[110];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        st.clear();

        for(int i = 0; i <= max(n, m); i++) {
            yo[i].clear();
            vals[i].clear();
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> b[i][j];
                st.insert({b[i][j], {i, j}});
                vals[i].insert(b[i][j]);
            }
        }
        for(int i = 0; i < m; i++) {
            auto it = st.begin();
            pair<int, pair<int, int> > tmp = *it;
            yo[tmp.second.first].push_back({i, tmp.first});
            // if(i != tmp.second.second) {
            //     cout << "hi " << i << " : " << tmp.second.first << " " << tmp.second.second << endl;
            //     // swap(b[tmp.second.first][i], b[tmp.second.first][tmp.second.second]);
            // }
            st.erase(it);

        }
        memset(c, -1, sizeof(c));
        for(int i = 0; i < n; i++) {
            for(PII pr: yo[i]) {
                c[i][ pr.first ] = pr.second;
                vals[i].erase(vals[i].find(pr.second));
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == -1) {
                    c[i][j] = *(vals[i].begin());
                    vals[i].erase(vals[i].begin());
                }
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/**
*/
