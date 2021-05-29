#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
 
template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class data  {
public:
    int num, pos;
    // data()  {}
    // data(int pp)    {
    //     num = pp;
    // }
    bool operator < (const data& b) const   {
        if(num == b.num)
            return pos < b.pos;
        return num > b.num;
    }
};

ordered_set<data> oset;

int n, q;
int ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        oset.insert({ara[i], i});
    }
    // for(data val: oset) {
    //     cout << val.num << " ";
    // }
    // cout << endl;

    for(int i = 1; i <= q; i++) {
        int tp, k;
        cin >> tp >> k;
        if(tp == 1) {
            // change ak to 1 - ak
            oset.erase({ara[k], k});
            ara[k] = 1 - ara[k];
            oset.insert({ara[k], k});
        }
        else {
            cout << (*oset.find_by_order(k - 1)).num << endl;
        }
    }
    return 0;
}
/**
 * tags: pbds, policy based data structure, ordered_set
 * 
 * only works for gnu c++14
*/
