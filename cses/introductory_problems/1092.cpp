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
    LL n;
    cin >> n;
    LL sum = n * (n + 1) / 2;
    if(sum % 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    LL cc = 0;
    int last;
    for(int i = 1; i <= n; i++) {
        last = i;
        cc += i;
        if(cc >= (sum / 2)) {
            break;
        }
    }
    int exclude = cc - (sum / 2);
    if(exclude != 0)
        cout << last - 1 << endl;
    else
        cout << last << endl;

    for(int i = 1; i <= last; i++) {
        if(i == exclude)
            continue;
        cout << i << " ";
    }
    cout << endl;
    if(exclude != 0)
        cout << n - last + 1 << endl << exclude << " ";
    else
        cout << n - last << endl;

    for(int i = last + 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
/**
*/
