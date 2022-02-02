#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[110][110];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        memset(ara, 0, sizeof(ara));
        int cnt = 1;
        // bool chk = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 && j == 1) {
                    continue;
                }
                if((i + j) % 2 == 0) {
                    ara[i][j] = cnt++;
                }
            }
        }
        ara[1][1] = cnt++;
        bool chk = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 && j == 2) {
                    continue;
                }
                if(i == 2 && j == 1) {
                    continue;
                }
                if(ara[i][j] == 0) {
                    ara[i][j] = cnt++;
                    chk = 1;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 && j == 2) {
                }
                else if(i == 2 && j == 1) {
                }
                else {
                    continue;
                }
                if(ara[i][j] == 0)
                    ara[i][j] = cnt++;
            }
        }
        if(chk || n == 1) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    cout << ara[i][j] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
/**
*/
