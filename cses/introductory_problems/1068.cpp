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
    cout << n << " ";
    while(n > 1) {
        if(n % 2) {
            n *= 3LL;
            n++;
        }
        else {
            n /= 2LL;
        }
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
/**
*/
