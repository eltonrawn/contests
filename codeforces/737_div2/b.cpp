#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
int ara[SZ], nara[SZ];
map<int, int> prevmp;
bool is_prev[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            nara[i] = ara[i];
            is_prev[i] = 0;
        }
        prevmp.clear();

        sort(nara + 1, nara + 1 + n);
        for(int i = 2; i <= n; i++) {
            prevmp[nara[i]] = nara[i - 1];
        }

        for(int i = 2; i <= n; i++) {
            if(prevmp.find(ara[i]) == prevmp.end()) continue;
            if(ara[i - 1] == prevmp[ara[i]]) {
                is_prev[i] = 1;
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(!is_prev[i]) cnt++;

        cout << (cnt <= k ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
*/
