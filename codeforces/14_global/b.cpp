#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

bool is_sqr(LL a) {
    LL sqr =sqrt(a);
    if(sqr * sqr == a) {
        return 1;
    }
    return 0;
}

int n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        if(n == 2 || n == 4 || (n % 2 == 0 && is_sqr(n / 2)) || (n % 4 == 0 && is_sqr(n / 4))) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
/**
*/
