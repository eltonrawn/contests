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
int freq[SZ][2];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        memset(freq, 0, sizeof(freq));
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            freq[ara[i]][i % 2]++;
        }

        bool chk = 1;
        sort(ara + 1, ara + n + 1);
        for(int i = 1; i <= n; i++) {
            if(freq[ara[i]][i % 2]) {
                freq[ara[i]][i % 2]--; continue;
            }
            chk = 0;
            break;
        }
        if(chk) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/**
*/
