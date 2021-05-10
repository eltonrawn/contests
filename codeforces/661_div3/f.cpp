#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 3010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<pair<int, int>> segments;
map<int, int> mp_ri, opp_idx;
int dp[SZ][SZ][2];

int get_pos(int val) {
    return lower_bound(segments.begin(), segments.end(), (pair<int, int>){val, 0}) - segments.begin();
}

int func(int pos, int rr, bool chk) {
    int ri = opp_idx[rr];
    if(pos == segments.size()) {
        return 0;
    }
    if(dp[pos][rr][chk] != -1) return dp[pos][rr][chk];
    int ans = 0;
    // not taking
    if(pos + 1 < segments.size() && segments[pos].first != segments[pos + 1].first) {
        ans = max(ans, func(pos + 1, rr, 0));
    }
    else {
        ans = max(ans, func(pos + 1, rr, chk));
    }
    

    /// taking
    if(segments[pos].second <= ri) {
        if(chk == 0 || segments[pos].second != ri) {
            int tmp = 1 + func(get_pos(segments[pos].first), mp_ri[segments[pos].second], 1);
            tmp += func(get_pos(segments[pos].second + 1), rr, 0);
            ans = max(ans, tmp);
        }
    }

    return dp[pos][rr][chk] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        segments.clear(); mp_ri.clear(); opp_idx.clear();
        int idx = 1;
        int mxri = 0;
        for(int i = 1; i <= n; i++) {
            int l, r; cin >> l >> r;
            segments.push_back({l, r});
            mxri = max(mxri, r);

            if(mp_ri[r] == 0) {
                mp_ri[r] = idx;
                opp_idx[idx] = r;
                idx++;
            }
        }
        sort(segments.begin(), segments.end());
        // memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= segments.size(); i++) {
            for(int j = 0; j <= idx; j++) {
                for(int k = 0; k <= 1; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << func(0, mp_ri[mxri], 0) << endl;
    }
    return 0;
}
/**
*/
