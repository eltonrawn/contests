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

/****************************short sieve and prime fact generate start***********************************/
bool flag[MX];
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
}
/****************************short sieve and prime fact generate end***********************************/

set<PII> st[MX];
int n, q;
int ara[MX];
set<PII> tmp;

LL ans = 1;

void decrease_st(int pp) {
    // cout << pp << " " << st[pp].size() << endl;
    if(st[pp].size() != n) {
        return;
    }
    tmp.clear();
    
    int mn = INT_MAX;
    for(PII val: st[pp]) {
        mn = min(mn, val.S);
    }
    
    for(PII val: st[pp]) {
        if(val.S - mn) {
            tmp.insert({val.F, val.S - mn});
        }
    }
    st[pp] = tmp;
    FOR(i, 1, mn) {
        ans *= (LL)pp;
        ans %= MOD;
    }
    
}

void ins_st(int pp, int a, int b) {
    auto it = st[pp].lower_bound({a, 0});
    
    if(it == st[pp].end()) {st[ pp ].insert({a, b});return;}

    PII vv = *it;

    if(vv.F != a) {st[ pp ].insert({a, b});return;}

    st[pp].erase(it);
    st[pp].insert({vv.F, vv.S + b});
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    gen_sieve(MX - 3);
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> ara[i];
        prime_fact(ara[i]);
        for(PII val: fact) {
            ins_st(val.F, i, val.S);
            decrease_st(val.F);
        }
    }

    FOR(i, 1, q) {
        int pos, val;
        cin >> pos >> val;
        prime_fact(val);
        for(PII val: fact) {
            ins_st(val.F, pos, val.S);
            decrease_st(val.F);
        }
        cout << ans << "\n";;
    }

    
    return 0;
}
/**
*/
