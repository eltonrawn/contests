#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
int vv[SZ];
map<int, int> freq;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        freq.clear();
        cin >> n >> x;
        for(int i = 1; i <= n; i++) {
            cin >> vv[i];
            if(vv[i] >= x) freq[1]++;
            else freq[x / vv[i] + ((x % vv[i]) ? 1 : 0)]++;
        }
        int ans = 0;
        int hold = 0;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            hold += it->second;
            ans += hold / it->first;
            hold %= it->first;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
