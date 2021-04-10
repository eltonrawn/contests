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

int sz;
PLL ara[110];
LL sum = 0;


/****************************short sieve and prime fact generate start***********************************/
 
vector<PII> fact;
bool prime_fact(LL tmp)  {
    fact.clear();
    for(LL i = 1; i <= sz; i++)   {
        LL pr = ara[i].F;
        if(tmp % pr == 0) {
            LL cnt = 0;
            while(tmp % pr == 0) {
                tmp /= pr;
                cnt++;
            }
            if(cnt > ara[i].S) {
                return 0;
            }
            fact.PB({pr, cnt});
        }
    }
    if(tmp != 1)    {
        return 0;
        LL cnt = 1;
        fact.PB({tmp, cnt});
    }
    return 1;
    // sort(fact.begin(), fact.end());
}
/****************************short sieve and prime fact generate end***********************************/

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        sum = 0;
        cin >> sz;
        FOR(i, 1, sz) {
            cin >> ara[i].F >> ara[i].S;
            sum += (ara[i].F * ara[i].S);
        }
        LL ans = 0;
        for(LL i = sum; i >= max(1LL, sum - 10000); i--) {
            if(!prime_fact(i)) {
                continue;
            }
            LL ss = 0;
            for(PII yo: fact) {
                ss += (yo.S * yo.F);
                // cout << i << " : " << yo.F << " " << yo.S << " " << ss << endl;
            }
            if(ss + i == sum) {
                ans = i;
                break;
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
/**
 * 499000000000000000
 * 5 * 10^17
 * 
 * 
*/
