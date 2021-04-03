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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, w;
int ara[MX];
multiset<int> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> w;
        st.clear();
        FOR(i, 0, n - 1) {
            cin >> ara[i];
            st.insert(ara[i]);
        }
        int ans = 0;
        while(!st.empty()) {
            ans++;
            int yo = w;
            while(!st.empty() && yo) {
                auto it = st.lower_bound(yo);
                if(it == st.end() || *it > yo) {
                    if(it == st.begin()) {
                        break;
                    }
                    it--;
                }
                // cout << yo << " " << *it << endl;
                yo -= *it;
                
                st.erase(it);
            }
        }
        cout << ans << "\n";

    }
    return 0;
}
/**
*/
