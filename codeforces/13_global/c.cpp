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
int use[SZ];

LL update(int le, int ri) {

    LL cnt = 0;
    for(int i = le; i <= min(n, ri); i++) {
        use[i]++; cnt++;
    }
    return cnt;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            use[i] = 0;
        }
        LL hand = 0;
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            use[i] += hand;
            ans += max(0, ara[i] - 1 - use[i]);
            use[i] = max(ara[i] - 1, use[i]);

            if(ara[i] != 1)
                update(i + 2, i + ara[i]);

            hand = use[i] - (ara[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
