#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
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

/****************************short sieve and prime fact generate start***********************************/
bool flag[2000020];
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
    gen_sieve(1000010);
    // for(int i = 2; i <= 100; i++) {
    //     prime_fact(i);
    //     set<int> st;
    //     for(PII val: fact) {
    //         st.insert(val.first);
    //     }
    //     if(st.size() > 1) continue;
    //     cout << i << endl;
    // }
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        // cout << n << endl;
        LL ans = 0;
        for(LL i = 2; n; i++) {
            prime_fact(i);
            set<int> st;
            for(PII val: fact) {
                st.insert(val.first);
            }
            if(st.size() > 1) continue;
            // cout << i << " : " << i << endl;
            LL top = (*st.begin());
            // cout << "straight : " << (n / top) * (top - 1) * i + ((n % top) * i) << endl;
            // val =  (n / top) * (top - 1) * i;
            // val += (n % top) * i;
            // LL vag = n / top;
            // LL yoyo = n * vag;

            // LL val = (yoyo * mod_inv(top)) % MOD;
            LL val = (n / top);
            // cout << "v1 " << val << endl;
            // val = (((val - (n % top)) % MOD) + MOD) % MOD;
            // cout << "v2 " << val << endl;

            LL topmin = ((((top - 1LL) % MOD) + MOD) % MOD);
            val = (val * topmin) % MOD;
            val = (val * i) % MOD;
            // cout << "val " << val << endl;
            val = val + ((n % top) * i) % MOD;
            // cout << i << " : " << val << endl;
            ans = (ans + val) % MOD;
            
            n /= top;
            // n = (n * mod_inv(top)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
