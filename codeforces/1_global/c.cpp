#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/****************************short sieve and prime fact generate start***********************************/
bool flag[1000010];
vector<int> prime;
 
void gen_sieve(int limit)	{
    memset(flag, 0, sizeof(flag));
	int sqrt_n = sqrt(limit);
	for (int i = 3; i <= sqrt_n; i += 2)	{
		if (!flag[i])
			for(int j = i * i; j <= limit; j += (i * 2)) flag[j] = 1;
	}
	prime.clear();prime.push_back(2);
    for(int i = 3; i <= limit; i += 2)   {
        if(flag[i] == 0)prime.push_back(i);
    }
}
 
vector<PLL> fact;
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
            fact.push_back({prime[i], cnt});
        }
        sqrtn = sqrt(tmp);
    }
    if(tmp != 1)    {
        LL cnt = 1;
        fact.push_back({tmp, cnt});
    }
    // sort(fact.begin(), fact.end());
}
/****************************short sieve and prime fact generate end***********************************/

LL n;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    gen_sieve(1000000);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int mxbit = 0;
        for(int i = 0; i < 40; i++) {
            if(n & (1LL << i)) mxbit = i;
        }
        if((1LL << (mxbit + 1)) - 1 != n) {
            cout << (1LL << (mxbit + 1)) - 1 << endl;
            continue;
        }
        
        prime_fact(n);
        sort(fact.begin(), fact.end());
        cout << n / fact[0].first << endl;

    }
    return 0;
}
/**
*/
