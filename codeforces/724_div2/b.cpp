#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str;

string ans;

bool chk(string ss) {
    for(int i = 0; i < str.size(); i++) {
        bool chk = 1;
        for(int j = 0; j < ss.size(); j++) {
            if(i + j >= str.size() || str[i + j] != ss[j]) {
                chk = 0; break;
            }
        }
        if(chk) return 0;
    }
    ans = ss;
    return 1;
}

bool func(int len, string ss) {
    if(len == 0) {
        return chk(ss);
    }
    for(char ch = 'a'; ch <= 'z'; ch++) {
        if(func(len - 1, ss + ch)) {
            return 1;
        }
    }
    return 0;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        ans = "";
        cin >> n >> str;
        /// 3 is enough
        for(int i = 1; i <= 5; i++) {
            if(func(i, ""))
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
