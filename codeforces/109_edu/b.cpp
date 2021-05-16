#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[55];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        bool is_sorted = 1;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            if(ara[i] != i) is_sorted = 0;
        }
        if(is_sorted) {
            cout << 0 << endl;
            continue;
        }
        if(ara[1] == 1 || ara[n] == n) {
            cout << 1 << endl;
            continue;
        }
        if(ara[1] == n && ara[n] == 1) {
            cout << 3 << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}
/**
*/
