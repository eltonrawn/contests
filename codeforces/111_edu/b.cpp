#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, a, b;
string str;


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> a >> b;
        cin >> str;
        LL ans = n * a;
        if(b >= 0) {
            ans += n * b;
        }
        else {
            LL one = 0;
            LL zero = 0;
            for(int i = 0; i < str.size(); i++) {
                int j;
                for(j = i; j < str.size(); j++) {
                    if(str[i] != str[j]) break;
                }
                j--;
                if(str[i] == '0') zero++;
                else one++;
                i = j;
            }
            // cout << "ans : " << ans << endl;
            ans += (min(one, zero) + 1LL) * b;
            // cout << "ans : " << ans << endl;
        }
        cout << ans << endl;

    }
    return 0;
}
/**
101010101
10101010
01010101
0101010
*/
