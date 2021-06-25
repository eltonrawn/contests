#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[21];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    LL sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
        sum += ara[i];
    }
    LL diff = LLONG_MAX;
    LL can = -1;
    for(int i = 0; i < (1 << n); i++) {
        LL ss = 0;
        for(int j = 0; j < n ; j++) {
            if(i & (1 << j)) {
                ss += ara[j];
            }
        }
        diff = min(diff, abs(ss - (sum - ss)));
    }
    cout << diff << endl;

    return 0;
}
/**
*/
