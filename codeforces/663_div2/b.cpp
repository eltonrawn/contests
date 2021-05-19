#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string str[101];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(str[i][m - 1] != 'D') {
                ans++;
            }
        }
        for(int j = 0; j < m - 1; j++) {
            if(str[n - 1][j] != 'R') {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
