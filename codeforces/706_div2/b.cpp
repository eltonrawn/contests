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

int n, k;
vector<int> ara;
map<int, int> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);tt
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        ara.resize(n);
        mp.clear();
        FOR(i, 0, n - 1) {
            cin >> ara[i];
            mp[ ara[i] ] = 1;
        }
        sort(ara.begin(), ara.end());
        ara.erase(unique(ara.begin(), ara.end()), ara.end());

        int mex = n;
        int max = ara.back();
        for(int i = 0; i < ara.size(); i++) {
            if(i != ara[i]) {
                mex = i;
                break;
            }
        }
        int nn = (mex + max + 1) / 2;
        if(nn > max) {
            cout << ara.size() + k << "\n";
        }
        else if(mp[ nn ] || k == 0) {
            cout << ara.size() + 0 << "\n";
        }
        else {
            cout << ara.size() + 1 << "\n";
        }

    }
    return 0;
}
/**
*/
