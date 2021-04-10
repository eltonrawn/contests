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

int n, l, r, s;
bool yoyo[510];
int ans[510];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> l >> r >> s;
        MEM(yoyo, 0);
        int cnt = r - l + 1;
        int sum = 0;
        FOR(i, 1, cnt) {
            sum += i;
            if(sum > s) {
                sum = -1;
                break;
            }
            yoyo[i] = 1;
        }
        if(sum == -1) {
            cout << "-1\n";
            continue;
        }
        int cur = n;
        ROF(i, cnt, 1) {
            if(cur <= i) {
                break;
            }
            yoyo[i] = 0;
            yoyo[i + min(s - sum, cur - i)] = 1;
            sum += min(s - sum, cur - i);
            cur--;
        }
        if(sum != s) {
            cout << "-1\n";
            continue;
        }

        cur = 1;
        FOR(i, 1, n) {
            if(i >= l && i <= r) {continue;}
            while(yoyo[cur]) {cur++;}
            ans[i] = cur++;
        }
        cur = 1;
        FOR(i, 1, n) {
            if(i >= l && i <= r) {}
            else {continue;}
            while(!yoyo[cur]) {cur++;}
            ans[i] = cur++;
        }
        FOR(i, 1, n) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
*/
