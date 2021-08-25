#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
string str;
int lens[26][SZ], rival[26][SZ];
int dp[SZ];

bool chk(int sz) {
    for(int ch = 0; ch < k; ch++) {
        int ri_len = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(str[i] == '?' || str[i] == (ch + 'a')) {
                lens[ch][i] = ri_len + 1;
            }
            else
                lens[ch][i] = 0;
            ri_len = lens[ch][i];
        }
    }


    for(int ch = 0; ch < k; ch++) {
        int ri_val = 1000000000;
        for(int i = n - 1; i >= 0; i--) {
            if(lens[ch][i] >= sz) {
                rival[ch][i] = i;
            }
            else {
                rival[ch][i] = ri_val;
            }
            ri_val = rival[ch][i];
        }
    }
    // cout << "hi1" << endl;

    dp[0] = 0;
    for(int mask = 1; mask < (1 << k); mask++) {
        dp[mask] = 1000000000;
        for(int j = 0; j < k; j++) {
            if(!(mask & (1 << j))) continue;
            int nmask = mask & ~(1 << j);
            // cout << mask << " " << nmask << endl;
            if(dp[nmask] < n && rival[j][ dp[nmask] ] < n)
                dp[mask] = min(dp[mask], rival[ j ][ dp[nmask] ] + sz);
        }
    }

    // cout << "hi1" << endl;
    
    if(dp[(1 << k) - 1] <= n) return 1;
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k >> str;
        int lo = 0, hi = str.size();
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if(chk(mid)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << endl;
    // }
    return 0;
}
/**
*/
