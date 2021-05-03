#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, x;
LL w[110];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> x;
        LL sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> w[i];
            sum += w[i];
        }
        if(sum < x) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                cout << w[i] << " ";
            }
            cout << endl;
            continue;
        }
        sort(w, w + n);
        multiset<LL> sep;
        LL cc = 0;
        multiset<LL> st;
        for(int i = 0; i < n; i++) {
            if(cc + w[i] == x) {
                if(st.empty()) {
                    sep.insert(w[i]);
                    continue;
                }
                sep.insert(*st.begin());
                cc -= *st.begin();
                st.erase(st.begin());
            }
            st.insert(w[i]);
            cc += w[i];
        }
        if(cc <= x) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(LL val: st) {
            cout << val << " ";
        }
        for(LL val: sep) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
