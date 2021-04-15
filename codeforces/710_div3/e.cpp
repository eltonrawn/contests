#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[MX];
set<int> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            cin >> ara[i];
        }
        st.clear();
        FOR(i, 1, n) {
            st.insert(i);
        }
        FOR(i, 1, n) {
            if(st.find(ara[i]) != st.end()) {
                cout << ara[i] << " ";
                st.erase(ara[i]);
            }
            else {
                cout << (*st.begin()) << " ";
                st.erase(st.begin());
            }
        }
        cout << endl;

        st.clear();
        FOR(i, 1, n) {
            st.insert(i);
        }
        FOR(i, 1, n) {
            if(st.find(ara[i]) != st.end()) {
                cout << ara[i] << " ";
                st.erase(ara[i]);
            }
            else {
                auto it = st.lower_bound(ara[i]);
                it--;
                cout << (*it) << " ";
                st.erase(it);
            }
        }
        cout << endl;
    }
    return 0;
}
/**
*/
