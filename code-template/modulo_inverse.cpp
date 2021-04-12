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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


LL bm(LL base, LL power) {    //bm represents bigmod
    if(power == 0)  {
        return 1;
    }
    if(power % 2 == 0)  {
        LL ret = bm(base, power / 2);
        return (ret * ret) % MOD;
    }
    else    {
        return (base * bm(base, power - 1)) % MOD;
    }
}
 
LL mod_inv(LL num)   {
    //fermat's little theorem
    //modu should be prime to use fermat
    return bm(num, MOD - 2);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    mod_inv(10);
    return 0;
}
/**
 * tags: modulo inverse
*/
