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
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000
 
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n, q;
int ara[MX];
vector<int> vv[MX];
map<int, int> mp;
 
 
int func(int l, int r) {
    // cout << l << " " << r << endl;
    int mx = (r - l + 1 + 1) / 2;
    int trr = min(r -l + 1, 30);
    mp.clear();
    for(int i = 1; i <= trr; i++) {
        int pos = (rng() % (r - l + 1)) + l;
        if(mp[pos]) {
            i--;
            continue;
        }
        mp[pos] = 1;
        int val = ara[pos];
        int soso1 = lower_bound(vv[val].begin(), vv[val].end(), l) - vv[val].begin();
        if(soso1 >= vv[val].size() || soso1 + mx >= vv[val].size() || vv[val][soso1 + mx] > r) {
            continue;
        }
 
        int soso2 = upper_bound(vv[val].begin(), vv[val].end(), r) - vv[val].begin();
        soso2--;
 
        int num = soso2 - soso1 + 1;
        int baki = (r - l + 1) - num;
 
        // cout << "num-baki : " << num << " " << baki << endl;
 
        int ans = baki;
        num -= baki * 2;
 
        ans += num;
        return ans;
    }
    return 1;
}
 
 
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    FastIO;
 
    // FOR(i, 1, 20) {
    //     cout << i << " : " << ((i + 1) / 2) << endl;
    // }
    // return 0;
 
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> ara[i];
        vv[ ara[i] ].PB(i);
    }
    FOR(i, 1, q) {
        int l, r;
        cin >> l >> r;
        int ans = func(l, r);
        cout << ans << endl;
    }
    return 0;
}
/**
*/