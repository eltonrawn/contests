#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
 
template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> oset;

int n, k;
int pnt[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= 2 * n; i++) {
            pnt[i] = 0;
        }
        
        for(int i = 1; i <= k; i++) {
            int a, b; cin >> a >> b;
            int l = min(a, b);
            int r = max(a, b);
            pnt[l] = r;
            pnt[r] = l;
        }
        vector<int> not_taken;
        for(int i = 1; i <= 2 * n; i++) {
            if(pnt[i] == 0) not_taken.push_back(i);
        }
        for(int i = 0; i < not_taken.size(); i++) {
            if(i + not_taken.size() / 2 >= not_taken.size()) break;
            
            int l = not_taken[i];
            int r = not_taken[i + not_taken.size() / 2];
            pnt[l] = r;
            pnt[r] = l;
        }

        int ans = 0;
        oset.clear();
        for(int i = 1; i <= 2 * n; i++) {
            if(pnt[i] > i) {
                ans += oset.order_of_key(pnt[i]);
                oset.insert(pnt[i]);
            }
            else {
                oset.erase(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
