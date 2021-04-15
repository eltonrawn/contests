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
map<int, int> mp;
multiset<int> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        mp.clear();
        st.clear();
        FOR(i, 0, n - 1) {
            cin >> ara[i];
            mp[ ara[i] ]++;
        }
        for(auto it: mp) {
            st.insert(it.second);
        }
        while(st.size() > 1) {
            auto it = st.end();it--;
            int v1 = *it;st.erase(it);

            it = st.end();it--;
            int v2 = *it;st.erase(it);
            // cout << v1 << " " << v2 << endl;

            v1--;v2--;
            if(v1) {st.insert(v1);}
            if(v2) {st.insert(v2);}
        }
        cout << (*st.begin()) << endl;

    }
    return 0;
}
/**
*/
