#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    LL sum = 0;
    for(int i = 1; i < n; i++) {
        LL tmp; cin >> tmp;
        sum += tmp;
    }
    cout << (n * (n + 1)) / 2 - sum << endl;
    return 0;
}
/**
*/
