#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    LL ans = 0;
    for(int i = 2; i <= n; i++) {
        if(ara[i - 1] > ara[i]) {
            ans += ara[i - 1] - ara[i];
            ara[i] = ara[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}
/**
5
3 2 5 1 7

0 1 0 4
*/
