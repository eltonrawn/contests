#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/****************************short sieve and prime fact generate start***********************************/
bool flag[SZ];
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


LL my_pow(int val, int cnt) {
    LL ans = 1;
    for(int i = 1; i <= cnt; i++) {
        ans *= val;
    }
    return ans;
}

int n;
int ara[SZ];
map<PII, int> freq;
map<int, int> mx_fact;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    gen_sieve(SZ - 1);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }

    for(int i = 1; i <= n; i++) {
        prime_fact(ara[i]);
        for(PII ff: fact) {
            int pr = ff.first;
            int cnt = ff.second;
            freq[ff]++;
            mx_fact[pr] = max(mx_fact[pr], cnt);
        }
    }
    LL ans = 1LL;
    for(auto it: mx_fact) {
        int pr = it.first;
        int cnt = it.second;
        int csum = 0;
        for(int i = cnt; i >= 1; i--) {
            csum += freq[{pr, i}];
            if(csum >= n - 1) {
                ans *= my_pow(pr, i);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
/**
*/
