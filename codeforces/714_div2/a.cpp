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

int n, k;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        int cur = n;
        int less = n - k;
        vector<int> ans;
        bool chk = 1;
        if(less >= 1) {
            ans.PB(less);
            less--;
        }
        else {
            chk = 0;
        }
        
        FOR(i, 1, k) {
            ans.PB(cur);
            if(less < 1) {
                chk = 0;
                break;
            }
            // cout << cur << " " << less << "\n";

            ans.PB(less);

            cur--;
            less--;
            
        }
        
        // cout << "ans : ";
        if(chk == 0) {
            cout << -1 << "\n";
            continue;
        }

        while(less > 0) {
            ans.PB(less);
            less--;
        }
        
        for(int val: ans) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
*/
