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
#define MX 200010
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
 
class cmp {
public:
    bool operator()(int a, int b) {
        return b < a;
    }
};
 
int n, k;
int ara[MX];
vector<int> vv[10000010];
vector<int> unq;
set<int, cmp> st;
int dp[MX][22];
 
void dp_state(int i) {
    FOR(j1, 0, k) {
        int cnt = 0;
 
        // dp[i][j1] = dp[i - 1][j1] + 1;

        for(int pos: st) {
            if(cnt > j1) {
                break;
            }
            dp[i][j1] = min(dp[i][j1], dp[pos][j1 - cnt] + 1);
            // cout << ans << " " << j1 << " " << cnt << " " << pos << " " << lr[pp].F << " " << pp << " : " << dp[pp][j1 - cnt] + 1 << "\n";
            cnt++;
        }
    }
}
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    gen_sieve(10000010);

    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k;
        st.insert(0);

        FOR(i, 1, n) {
            FOR(j, 0, k) {
                dp[i][j] = INF;
            }
        }
 
        FOR(i, 1, n) {
            cin >> ara[i];
            prime_fact(ara[i]);
            LL gun = 1LL;
            for(PII val: fact) {
                if(val.S % 2) {
                    gun *= val.F;
                }
            }

            if(!vv[gun].empty()) {
                st.insert(vv[gun].back());
            }
            dp_state(i);
            vv[gun].PB(i);
            unq.PB(gun);
        }


        // FOR(i, 0, ans) {
        //     FOR(j, 0, k) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
 
        cout << dp[n][k] << "\n";
 
 
        /// clear all
        for(int val: unq) {
            vv[val].clear();
        }

        unq.clear();
        st.clear();
    }
    return 0;
}
/**
*/