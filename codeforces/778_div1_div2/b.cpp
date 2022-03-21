#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
int taken[30];


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        memset(taken, 0, sizeof(taken));
        cin >> str;
        int ans = str.size();
        for(int i = str.size() - 1; i >= 0; i--) {
            if(taken[str[i] - 'a'] == 0) ans = i;
            taken[str[i] - 'a']++;
        }
        string pr = "";
        for(int i = ans; i < str.size(); i++) {
            pr += str[i];
        }
        cout << pr << endl;
    }
    return 0;
}
/**
*/
