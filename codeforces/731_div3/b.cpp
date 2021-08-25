#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> str;
        int le = -1, ri = -1;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == 'a') {
                le = i - 1;
                ri = i + 1;
                break;
            }
        }
        
        if(ri == -1) {
            cout << "NO" << endl;
            continue;
        }
        bool chk = 1;        
        for(char ch = 'b'; ch < ('a' + str.size()); ch++) {
            if(le >= 0 && str[le] == ch) {
                le--;
                continue;
            }
            if(ri < str.size() && str[ri] == ch) {
                ri++;
                continue;
            }
            chk = 0; break;
        }
        cout << (chk ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
*/
