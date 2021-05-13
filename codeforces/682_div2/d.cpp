#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
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
    cin >> n;
    int xx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        xx ^= ara[i];
    }
    if(n % 2 == 0 && xx) {
        cout << "NO" << endl;
        return 0;
    }
    if(n % 2 == 0) n--;
    cout << "YES" << endl;
    cout << n - 1 << endl;
    for(int i = 1; i < n; i += 2) {
        cout << i << " " << i + 1 << " " << i + 2 << endl;
    }
    for(int i = 1; i < n; i += 2) {
        cout << i << " " << i + 1 << " " << n << endl;
    }

    return 0;
}
/**
*/
