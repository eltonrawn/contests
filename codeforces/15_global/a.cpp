#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str, nstr;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        cin >> str;
        nstr = str;
        sort(nstr.begin(), nstr.end());
        int cnt = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != nstr[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
/**
*/