#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int half = (n + 2) / 2;
    for(int i = 1, j = half; j <= n; i++, j++) {
        cout << j << " ";
        if(i < half)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
/**
*/
