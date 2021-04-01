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


/****************************short sieve and prime fact generate start***********************************/
bool flag[10000020];
vector<int> prime;
 
void gen_sieve(int limit)	{
    MEM(flag, 0);
	int sqrt_n = sqrt(limit);
	for (int i = 3; i <= sqrt_n; i += 2)	{
		if (!flag[i])
			for(int j = i * i; j <= limit; j += (i * 2)) flag[j] = 1;
	}
	prime.clear();prime.PB(2);
    for(int i = 3; i <= limit; i += 2)   {
        if(flag[i] == 0)prime.PB(i);
    }
}
 
vector<PII> fact;
void prime_fact(LL tmp)  {
    fact.clear();
    LL sqrtn;
    sqrtn = sqrt(tmp);
    for(LL i = 0; prime[i] <= sqrtn; i++)   {
        if(tmp % prime[i] == 0) {
            LL cnt = 0;
            while(tmp % prime[i] == 0) {
                tmp /= prime[i];
                cnt++;
            }
            fact.PB({prime[i], cnt});
        }
        sqrtn = sqrt(tmp);
    }
    if(tmp != 1)    {
        LL cnt = 1;
        fact.PB({tmp, cnt});
    }
    // sort(fact.begin(), fact.end());
}
/****************************short sieve and prime fact generate end***********************************/

/****************************divisor generation start***********************************/
 
vector<int> divisors;
void gen_divisors(int x) {
    prime_fact(x);
    divisors.clear();
    divisors.PB(1);
    int sz = fact.size(); //size of prime factorization
    FOR(i, 0, sz - 1)   {
        int tmpsz = divisors.size();
        int gun = 1;
        FOR(j, 1, fact[i].S)   {
            gun *= fact[i].F;
            FOR(k, 0, tmpsz - 1)   {
                divisors.PB(divisors[k] * gun);
            }
        }
    }
}
/****************************divisor generation end***********************************/

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;

    gen_sieve(10000010);
    gen_divisors(100);

    return 0;
}
/**
 * tags: number theory
*/