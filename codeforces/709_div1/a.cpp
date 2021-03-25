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
vector<int> vv[MX];
int cap[MX];
int ans[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        FOR(i, 1, m) {
            vv[i].clear();
            ans[i] = 0;
        }
        FOR(i, 1, n) {
            cap[i] = (m + 1) / 2;
        }
        FOR(i, 1, m) {
            int cnt;
            cin >> cnt;
            FOR(j, 1, cnt) {
                int val;cin >> val;
                vv[i].PB(val);
            }
        }
        bool chk = 1;
        FOR(i, 1, m) {
            if(vv[i].size() > 1) {
                continue;
            }
            if(cap[ vv[i].back() ] <= 0) {
                chk = 0;
                break;
            }
            cap[ vv[i].back() ]--;
            ans[i] = vv[i].back();
        }
        if(!chk) {
            cout << "NO\n";
            continue;
        }
        
        FOR(i, 1, m) {
            if(ans[i]) {
                continue;
            }
            for(int val: vv[i]) {
                if(cap[val] > 0) {
                    ans[i] = val;
                    cap[val]--;
                    break;
                }
            }
        }
        cout << "YES\n";
        FOR(i, 1, m) {
            cout << ans[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}
/**
*/
