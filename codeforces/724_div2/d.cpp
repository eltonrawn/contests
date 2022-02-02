#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];

bool solve() {
    set<int> st;
    st.insert(ara[1]);
    for(int i = 2; i <= n; i++) {
        auto it = st.lower_bound(ara[i - 1]);
        if(ara[i] < ara[i - 1]) {
            if(it == st.begin()) {
                st.insert(ara[i]); continue;
            }
            it--;
            if(*it <= ara[i]) {
                st.insert(ara[i]); continue;
            }
            return 0;
        }
        if(ara[i] > ara[i - 1]) {
            it++;
            if(it == st.end() || (*it >= ara[i])) {
                st.insert(ara[i]); continue;
            }
            return 0;
        }
    }
    return 1;
}

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
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
*/