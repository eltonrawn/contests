#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string s, ans_d = "", ans_s = "";


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for(int le = 0, ri = s.size() - 1; le <= ri;) {
        if(ans_d.size() * 2 + ans_s.size() >= s.size() / 2) break;
        if(le + 1 < ri - 1) {
            // atleast _ _ _ _
            /// one of these will be fulfilled
            if(s[le] == s[ri]) {
                ans_d += s[le];
                le++; ri--;
            }
            else if(s[le] == s[ri - 1]) {
                ans_d += s[le];
                le++;
                ri -= 2;
            }
            else if(s[le + 1] == s[ri]) {
                ans_d += s[le + 1];
                le += 2;
                ri--;
            }
            else if(s[le + 1] == s[ri - 1]) {
                ans_d += s[le + 1];
                le += 2;
                ri -= 2;
            }
            
        }
        else if(le + 1 < ri) {
            // _ _ _
            if(s[le] == s[ri]) {
                ans_d += s[le];
                le++; ri--;
            }
            else if(s[le] == s[ri - 1]) {
                ans_d += s[le];
                le++; ri -= 2;
            }
            else if(s[le + 1] == s[ri]) {
                ans_d += s[le + 1];
                le += 2; ri--;
            }
            else {
                le++; ri--;
            }
        }
        else if(le + 1 == ri) {
            // _ _
            if(s[le] == s[ri]) {
                ans_d += s[le];
                le++; ri--;
            }
            else {
                le++;
            }
        }
        else if(le == ri) {
            ans_s += s[le];
            le++; ri--;
        }
    }

    string ans = ans_d;
    ans += ans_s;
    reverse(ans_d.begin(), ans_d.end());
    ans += ans_d;
    cout << ans << endl;
    return 0;
}
/**
start: 2:52 pm
end: 3:14 pm
*/
