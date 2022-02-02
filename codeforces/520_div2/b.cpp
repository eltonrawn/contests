#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

/****************************short sieve and prime fact generate start***********************************/
bool flag[100010];
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


int n;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    gen_sieve(100000);
    cin >> n;
    prime_fact(n);

    if(n == 1) {
        cout << 1 << " " << 0 << endl;
        return 0;
    }

    bool chk = 0;
    int make = 1;
    int mx = 0, mn = INT_MAX;
    for(PII val: fact) {
        
        LL two = 1;
        for(; two < val.second; two *= 2LL) {}

        if(two != val.second) chk = 1;

        mx = max(mx, (int)log2(two)); mn = min(mn, (int)log2(two));
        make *= val.first;
        // cout << val.first << " " << val.second << endl;
    }

    if(mn != mx) {
        chk = 1;
    }

    // cout << "chk : " << chk << endl;

    cout << make << " " << chk + mx << endl;


    return 0;
}
/**
*/
