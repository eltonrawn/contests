#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
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

int n, ara[SZ];
set<PII> processing;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        while(!processing.empty()) {
            auto it = processing.begin();
            PII cur = *it;
            if(cur.first < i) {
                processing.erase(it);
                oset.erase(cur.second);
            }
            else break;
        }

        ans += oset.order_of_key(ara[i]);
        if(oset.find(ara[i]) != oset.end()) {
            ans++;
        }
        // ans += yoyo;

        oset.insert(i);
        processing.insert({ara[i], i});
    }
    cout << ans << endl;
    return 0;
}
/**
start: 5:41 pm
end: 6:29 pm
duration: 50 mins.
comment: couldn't find solution quickly. but final solution was pretty compact. have to be good in ds.
tags: pbds, repeat
*/
