#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
string s, t;
int dp[SZ][2];
 
const int inf = 1000000000;
 
vector<int> pos[26][2];
 
// int get_char_after(int after, char ch, bool is_odd, bool rest) {
//     for(int i = after; i < s.size(); i++) {
//         if(rest && i == after + 1) continue;
//         if(i % 2 == is_odd && s[i] == ch) return i;
//     }
//     return inf;
// }
 
int get_char_after(int after, char ch, bool is_odd, bool rest) {
    // for(int i = after; i < s.size(); i++) {
    //     if(rest && i == after + 1) continue;
    //     if(i % 2 == is_odd && s[i] == ch) return i;
    // }
    // return inf;
    int pp = lower_bound(pos[ch - 'a'][is_odd].begin(), pos[ch - 'a'][is_odd].end(), after) - pos[ch - 'a'][is_odd].begin();
    if(pp == pos[ch - 'a'][is_odd].size()) return inf;
    // if(rest && pos[ch - 'a'][is_odd][pp] == after + 1) pp++;
    // if(pp == pos[ch - 'a'][is_odd].size()) return inf;

    if(rest && (pos[ch - 'a'][is_odd][pp] - after) % 2)
        return inf;
    return pos[ch - 'a'][is_odd][pp];
}
 
void place_it(int &ans, int rep) {
    ans = min(ans, rep);
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> s >> t;
        for(int i = 0; i < 26; i++) {
            pos[i][0].clear(); pos[i][1].clear();
        }
        for(int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'][i % 2].push_back(i);
        }
        for(int i = 0; i < t.size(); i++) {
            if(i == 0) {
                dp[i][0] = get_char_after(0, t[i], 0, 0);
                dp[i][1] = get_char_after(0, t[i], 1, 0);
                continue;
            }
 
            /// place even
            dp[i][0] = inf;
            place_it(dp[i][0], get_char_after(dp[i - 1][0] + 1, t[i], 0, 1));
            place_it(dp[i][0], get_char_after(dp[i - 1][1] + 1, t[i], 0, 1));
 
            /// place odd
            dp[i][1] = inf;
            place_it(dp[i][1], get_char_after(dp[i - 1][0] + 1, t[i], 1, 1));
            place_it(dp[i][1], get_char_after(dp[i - 1][1] + 1, t[i], 1, 1));
 
            // cout << i << ": " << dp[i][0] << " " << dp[i][1] << endl;
 
        }
        if((dp[t.size() - 1][0] < s.size() && (s.size() - 1 - dp[t.size() - 1][0]) % 2 == 0) 
        || (dp[t.size() - 1][1] < s.size() && (s.size() - 1 - dp[t.size() - 1][1]) % 2 == 0)) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
/**
*/