#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL k;
string str;
vector<int> vv[30];

int get_nxt_pos(int pos, int ch) {
    int pp = upper_bound(vv[ch].begin(), vv[ch].end(), pos) - vv[ch].begin();
    if(pp == vv[ch].size()) return -1;
    return vv[ch][pp];
}

LL dp[110][110];

LL func(int pos, int left) {
    /// prefix made till this is the first occurence
    if(left == 0) {
        return 1;
    }
    if(dp[pos][left] != -1) {
        return dp[pos][left];
    }
    LL ans = 0;
    for(int i = 0; i < 30; i++) {
        int nxt_pos = get_nxt_pos(pos, i);
        if(nxt_pos == -1) continue;
        ans += func(nxt_pos, left - 1);
        ans = min(ans, (long long)k);
    }
    return dp[pos][left] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        vv[str[i] - 'a'].push_back(i);
    }

    LL ans = 0;
    LL taken = 0;
    for(int len = str.size(); len >= 0; len--) {
        if(taken == k) {
            break;
        }
        if(len == 0) {
            taken++; ans += str.size();
            break;
        }
        for(int i = 0; i < 30; i++) {
            if(taken == k) break;
            int nxt_pos = get_nxt_pos(-1, i);
            if(nxt_pos == -1) continue;
            
            LL got;
            if(taken + func(nxt_pos, len - 1) >= k) got = k - taken;
            else got = func(nxt_pos, len - 1);

            ans += got * (long long)(str.size() - len);
            taken += got;
        }
        // cout << i << " " << taken << " " << ans << endl;
    }

    if(taken != k) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
/**
coding start: 12:44 pm
*/
