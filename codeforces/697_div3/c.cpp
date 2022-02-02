#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int b_num, g_num, coup_num;
int boys[SZ], girls[SZ];
int boys_cnt[SZ], girls_cnt[SZ];
map< pair<int, int>, int> bc_pair;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        
        cin >> b_num >> g_num >> coup_num;

        bc_pair.clear();
        for(int i = 1; i <= max(b_num, g_num); i++) {
            boys_cnt[i] = 0;
            girls_cnt[i] = 0;
        }
        for(int i = 1; i <= coup_num; i++) {
            cin >> boys[i];
            boys_cnt[boys[i]]++;
        }
        for(int i = 1; i <= coup_num; i++) {
            cin >> girls[i];
            girls_cnt[girls[i]]++;
        }
        for(int i = 1; i <= coup_num; i++) {
            bc_pair[{boys[i], girls[i]}]++;
        }
        LL ans = 0;
        for(int i = 1; i <= coup_num; i++) {
            LL total = boys_cnt[boys[i]];
            total += girls_cnt[girls[i]];
            total -= bc_pair[{boys[i], girls[i]}];
            ans += coup_num - total;
        }
        cout << ans / 2LL << endl;

    }
    return 0;
}
/**
*/