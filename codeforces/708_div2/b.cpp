#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[MX], cnt[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;

        FOR(i, 0, m) {
            cnt[i] = 0;
        }

        FOR(i, 0, n - 1) {
            cin >> ara[i];
            int khop;
            if(ara[i] % m == 0) {
                khop = 0;
            }
            else {
                khop = (((ara[i] / m) + 1) * m) - ara[i];
            }
            
            // cout << ara[i] << " : " << khop << endl;
            
            cnt[khop]++;
        }
        int ans = 0;
        FOR(i, 1, m - 1) {
            int j = m - i;
            if(i < j && (cnt[i] + cnt[j])) {
                int mn = min(cnt[i], cnt[j]);
                int mx = max(cnt[i], cnt[j]);
                // cout << "hi1 " << i << " " << j << " : " << mn << " " << min(mx, mn + 1) << endl;
                ans += cnt[i] + cnt[j] - (mn + min(mx, mn + 1)) + 1;
            }
            if(i == j && cnt[i]) {
                ans++;
                // cout << "hi2 " << i << " : " << cnt[i] << endl;
            }
        }
        
        if(cnt[0]) {
            // cout << "hi3 " << 0 << " : " << cnt[0] << endl;
            ans++;
        }
        // cout << "ans : ";
        cout << ans << "\n";
    }
    return 0;
}
/**
*/
