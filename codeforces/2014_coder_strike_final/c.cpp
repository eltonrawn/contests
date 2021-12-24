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

ordered_set<PII> oset;

int n, p;
PII ara[SZ];
set<int> adjl[SZ];
int cnt[SZ];
map<PII, int> prcnt;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    // scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++) {
        cin >> ara[i].first >> ara[i].second;
        // scanf("%d %d", &ara[i].first, &ara[i].second);
        if(ara[i].first > ara[i].second) swap(ara[i].first, ara[i].second);
        adjl[ara[i].first].insert(ara[i].second);
        cnt[ara[i].first]++;
        cnt[ara[i].second]++;
        prcnt[{ara[i].first, ara[i].second}]++;
    }

    for(int i = 1; i <= n; i++) {
        oset.insert({cnt[i], i});
    }

    LL ans = 0;
    for(int u = 1; u <= n; u++) {
        oset.erase({cnt[u], u});
        
        if(cnt[u] >= p) {
            ans += oset.size();
            continue;
        }

        for(int v: adjl[u]) {
            // oset.erase({cnt[v], v});
            // oset.insert({cnt[v] - prvec[u][i], v});

            if(cnt[v] - prcnt[{u, v}] < p - cnt[u]) {
                if(cnt[v] >= p - cnt[u]) {
                    ans--;
                }
            }
        }

        ans += (LL)oset.size() - (LL)oset.order_of_key({p - cnt[u], 0});

        // for(int i = 0; i < adjl[u].size(); i++) {
        //     int v = adjl[u][i];
        //     oset.erase({cnt[v] - prvec[u][i], v});
        //     oset.insert({cnt[v], v});
        // }
    }
    cout << ans << endl;
    // printf("%lld\n", ans);
    return 0;
}
/**
tag: pbds
start: 5 pm
end: 7:23 pm
duration: 2 hrs 23 mins
comment: dissapointing. Couldn't find out a stupid mistake.
*/
