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

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        n *= 2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> ara[i];
            if(ara[i] % 2) cnt++;
        }
        if(cnt == (n / 2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
/**
*/
