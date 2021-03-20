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

set<LL> ms1, ms2;
int n;
LL ara[100010];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        ms1.clear();
        ms2.clear();
        cin >> n;
        FOR(i, 1, n) {
            cin >> ara[i];
        }
        LL ans = LLONG_MAX;
        LL sum1 = 0, sum2 = 0;
        LL taken1 = 0, taken2 = 0;
        FOR(i, 1, n) {
            if(i % 2) {
                ms1.insert(ara[i]);
                sum1 += ara[i];
                taken1++;
            }
            else {
                ms2.insert(ara[i]);
                sum2 += ara[i];
                taken2++;
            }
            
            if(ms1.size() + ms2.size() < 2) {
                continue;
            }

            LL yo1 = sum1 + ((n - taken1) * (*ms1.begin()));
            LL yo2 = sum2 + ((n - taken2) * (*ms2.begin()));
            
            // cout << yo1 << " " << yo2 << endl;

            ans = min(ans, yo1 + yo2);
        }
        cout << ans << "\n";
    }
    return 0;
}
/**
*/
