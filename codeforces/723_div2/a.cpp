#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        sort(ara + 1, ara + n + 1);
        for(int i = 1, j = n; i < j; i++, j--) {
            cout << ara[i] << " " << ara[j] << " ";
        }
        // for(int i = 2; i <= n; i += 2) {
        //     cout << ara[i] << " ";
        // }
        cout << endl;
    }
    return 0;
}
/**
*/
