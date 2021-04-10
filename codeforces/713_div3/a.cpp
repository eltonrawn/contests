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
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[110], cnt[110];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        MEM(cnt, 0);
        cin >> n;
        vector<int> yo;
        FOR(i, 1, n) {
            cin >> ara[i];
            cnt[ ara[i] ]++;
            yo.PB(ara[i]);
        }
        sort(yo.begin(), yo.end());
        
        int ans = yo[0];
        if(cnt[ yo.back() ] == 1) {
            ans = yo.back();
        }
        // cout << "ans : " << ans << endl;

        FOR(i, 1, n) {
            if(ara[i] == ans) {
                cout << i << endl;
                break;
            }
        }
        // cout << ans << endl;
    }
    return 0;
}
/**
*/
