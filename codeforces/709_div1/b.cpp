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

int n;
int ara[MX];
set<int> pps, can;
vector<int> ans, tmp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 0, n - 1) {
            cin >> ara[i];
        }
        pps.clear();
        FOR(i, 0, n - 1) {
            pps.insert(i);
        }
        ans.clear();
        can.clear();
        for(int i = 0; i < n; i++) {
            int por = (i + 1) % n;
            if(__gcd(ara[i], ara[por]) == 1) {
                can.insert(i);
                // if(por == 0 && can.find(0) != can.end()) {
                    
                // }
                can.erase(por);
                pps.erase(por);
                ans.PB(por);
                i++;
            }
        }

        while(!can.empty()) {
            tmp.clear();
            for(int pos: can) {
                tmp.push_back(pos);
            }
            for(int pos: tmp) {
                if(can.find(pos) == can.end()) {
                    continue;
                }
                int por;
                if(pos == *pps.rbegin()) {
                    por = *pps.begin();
                }
                else {
                    por = *(pps.upper_bound(pos));
                }
                
                if(__gcd(ara[pos], ara[por]) == 1) {
                    can.erase(por);
                    pps.erase(por);
                    ans.PB(por);
                }
                else {
                    can.erase(pos);
                }
            }
        }
        cout << ans.size() << " ";
        for(int pos: ans) {
            cout << pos + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
*/
