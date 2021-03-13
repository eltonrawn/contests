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
 
int pre_up[MX], suff_up[MX];
int n;
int per[MX];
vector<PII> vv;
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    FOR(i, 1, n) {
        cin >> per[i];
    }
    FOR(i, 1, n) {
        if(per[i] > per[i - 1]) {
            pre_up[i] = pre_up[i - 1] + 1;
        }
        else {
            pre_up[i] = 1;
        }
        vv.PB({pre_up[i], i});
    }
    ROF(i, n, 1 ) {
        if(per[i] > per[i + 1]) {
            suff_up[i] = suff_up[i + 1] + 1;
        }
        else {
            suff_up[i] = 1;
        }
        vv.PB({suff_up[i], i});
    }
    sort(vv.begin(), vv.end(), greater<PII>());
    int ans = 0;
    FOR(i, 1, n) {
        if(pre_up[i] % 2 == suff_up[i] % 2) {
            if(pre_up[i] % 2 == 0) {
                /// lose
                continue;
            }
            if(pre_up[i] == suff_up[i]) {
                /// lose if there's another greater_eq than max(pre_up[i], suff_up[i])
                bool chk = 1;
                for(PII val: vv) {
                    if(val.S == i) {
                        continue;
                    }
                    if(val.F >= max(pre_up[i], suff_up[i])) {
                        chk = 0;
                    }
                    break;
                }
                if(chk == 0) {
                    continue;
                }
                /// otherwise win
                ans++;
                continue;
            }
            else {
                /// lose
                continue;
            }
        }
        /// lose
    }
    cout << ans;
    return 0;
}
/**
*/