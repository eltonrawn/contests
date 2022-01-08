#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL cnt = 0;

int n, k;
string s, t;


LL func(int pos, bool is_small) {
    if(pos == s.size()) {
        return 0;
    }
    LL ans = 0;
    if(is_small == 0) {
        if(s[pos] == t[pos]) {
            ans += 1;
            ans += func(pos + 1, is_small);
        }
        else {
            /// otherwise s will be def smaller
            ans += 2;
            ans += func(pos + 1, 1);
        }
        return ans;
    }

    ans += 2;
    if(s[pos] == t[pos]) {
        /// placing s[pos] = 'b' or placing t[pos] = 'a'
        cnt++;
    }
    else if(s[pos] == 'a' && t[pos] == 'b') {
        /// placing s[pos] = 'b' && placing t[pos] = 'a'
        cnt += 2;
    }

    LL cur_make = min((LL)k - 2, cnt);
    ans += cur_make;

    cnt *= 2LL;
    cnt = min(cnt, (LL)k - 2);

    ans += func(pos + 1, is_small);
    
    // cout << pos << " " << is_small << " " << make << " : " << ans << endl;
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s >> t;
    if(k == 1) cout << s.size() << endl;
    else cout << func(0, 0) << endl;

    return 0;
}
/**
start: 3 pm
rough idea: 3:31 pm
end: 5:12 pm

duration: 2 hours
comment: idea was slightly wrong. problem felt difficult

tags: repeat
*/
