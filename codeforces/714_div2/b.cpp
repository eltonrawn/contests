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
#define MOD 1000000007
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[MX];

LL dp[MX];

LL fact(LL pos) {
    if(pos == 0) {
        return 1;
    }
    if(dp[pos] != -1) {
        return dp[pos];
    }
    return dp[pos] = (pos * fact(pos - 1)) % MOD;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    MEM(dp, -1);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        int andd;
        FOR(i, 1, n) {
            cin >> ara[i];
            if(i == 1) {
                andd = ara[i];
                continue;
            }
            andd = andd & ara[i];
        }
        sort(ara + 1, ara + n + 1);

        LL mncnt = 0;
        FOR(i, 1, n) {
            if(ara[i] == ara[1]) {
                mncnt++;
            }
        }
        if(mncnt == 1) {
            // cout << "hi1 ";
            cout << 0 << "\n";
            continue;
        }
        // if(ara[1] == 0) {
        //     // cout << "hi2 ";
        //     cout << (((mncnt * (mncnt - 1)) % MOD) * fact(n - 2)) % MOD << "\n";
        //     continue;
        // }
        // cout << "gcd : " << gcd << endl;

        if(andd != ara[1]) {
            // cout << "hi3 ";
            cout << 0 << "\n";
            continue;
        }
        cout << (((mncnt * (mncnt - 1)) % MOD) * fact(n - 2)) % MOD << "\n";


    }
    return 0;
}
/**
*/
