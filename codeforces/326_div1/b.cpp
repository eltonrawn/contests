#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
LL n, k;
LL l;
int ara[SZ];
vector< LL > dp[SZ];
LL final_k, last_k_lim;
set<PII> st;
 
int get_next_pos(int val, int pos) {
    PII cur = {val, pos};
    auto it = st.upper_bound(cur);
    if(it == st.end()) return -1;
    return (*it).second;
}
 
LL func(int k_taken, int pos) {
    // cout << "inside : " << k_taken << " " << pos << endl;
    if(k_taken > final_k) {
        return 0;
    }
    if(dp[k_taken][pos] != -1) {
        return dp[k_taken][pos];
    }
 
    LL ans = 0;
    int nxt_pos = get_next_pos(ara[pos], pos);
 
    if(nxt_pos != -1) {
        /// don't take it
        ans += func(k_taken, nxt_pos);
        if(ans >= MOD) ans -= MOD;
    }
    
    /// +1 means finish here
    /// and + func() means take it and continue
    
    if(pos != 0) {
        if(k_taken == final_k && pos > last_k_lim) {}
        else {
            // cout << "inc " << k_taken << " " << pos << endl;
            ans += 1;
            nxt_pos = get_next_pos(ara[pos], 0);
            ans += func(k_taken + 1, nxt_pos);
            if(ans >= MOD) ans -= MOD;
        }
    }
    
 
    // cout << k_taken << " " << pos << " : " << ans << endl;
    return dp[k_taken][pos] = ans;
}
 
void init_dp() {
    /// initialize dp
    for(int i = 0; i <= k; i++) {
        dp[i].clear();
        for(int j = 0; j <= n; j++) {
            dp[i].push_back(-1);
        }
    }
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l >> k;
    
 
    ara[0] = 0; /// dummy position with minimum value
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        st.insert({ara[i], i});
    }
 
    LL segs = (LL)(l / n);
    LL rem = n;
    if(l % n) {
        segs++;
        rem = l % n;
    }
 
    LL ans = 0;
    if(segs > k) {
        final_k = k;
        last_k_lim = n;
        init_dp();
        ans += (segs - 1 - k + 1) % MOD * func(1, 0);
        ans %= MOD;
    }
 
    final_k = min(segs, k);
    last_k_lim = rem;
    init_dp();
 
    // cout << segs << " " << final_k << " " << last_k_lim << endl;
    
    for(int i = 0; i < final_k; i++) {
        ans += func(1 + i, 0);
        if(ans >= MOD) ans -= MOD;
        // cout << i << " : " << ans << endl;
    }
 
    cout << ans << endl;;
 
 
    return 0;
}
/**
start: 9 pm
duration: 4~5 hours
comment: was stuck in different ideas
tags: dp, repeat
*/