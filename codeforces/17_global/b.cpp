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

bool func(int le, int ri, int bad) {
    // cout << le << " " << ri << " : " << bad << endl;
    if(le > ri) {
        return 1;
    }
    if(ara[le] == ara[ri]) {
        return func(le + 1, ri - 1, bad);
    }
    if(ara[le] == bad) {
        return func(le + 1, ri, bad);
    }
    if(ara[ri] == bad) {
        return func(le, ri - 1, bad);
    }
    bool ans = 0;
    if(bad == -1) {
        ans = max(ans, func(le + 1, ri, ara[le]));
        ans = max(ans, func(le, ri - 1, ara[ri]));
    }
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        cout << (func(1, n, -1) == 1? "YES": "NO") << endl;
    }
    return 0;
}
/**
*/
