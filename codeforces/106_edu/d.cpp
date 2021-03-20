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


// /****************************short sieve and prime fact generate start***********************************/
// bool flag[10000020];
// vector<int> prime;
 
// void gen_sieve(int limit)	{
//     MEM(flag, 0);
// 	int sqrt_n = sqrt(limit);
// 	for (int i = 3; i <= sqrt_n; i += 2)	{
// 		if (!flag[i])
// 			for(int j = i * i; j <= limit; j += (i * 2)) flag[j] = 1;
// 	}
// 	prime.clear();prime.PB(2);
//     for(int i = 3; i <= limit; i += 2)   {
//         if(flag[i] == 0)prime.PB(i);
//     }
// }
 
// vector<PII> fact;
// void prime_fact(LL tmp)  {
//     fact.clear();
//     LL sqrtn;
//     sqrtn = sqrt(tmp);
//     for(LL i = 0; prime[i] <= sqrtn; i++)   {
//         if(tmp % prime[i] == 0) {
//             LL cnt = 0;
//             while(tmp % prime[i] == 0) {
//                 tmp /= prime[i];
//                 cnt++;
//             }
//             fact.PB({prime[i], cnt});
//         }
//         sqrtn = sqrt(tmp);
//     }
//     if(tmp != 1)    {
//         LL cnt = 1;
//         fact.PB({tmp, cnt});
//     }
//     // sort(fact.begin(), fact.end());
// }

int fact_memo[20000020];
vector<PII> fact;

void init_fact_sieve(int limit) {
    MEM(fact_memo, 0);
    int sqrt_n = sqrt(limit) + 1;
    for(int i = 2; i <= sqrt_n; i++) {
        if(fact_memo[i])
            continue;
        for(int j = (LL)i * i; j <= limit; j += i) {
            fact_memo[j] = i;
        }
    }
}

// void frec(int val, vector<int> &vv) {
//     if(val == 1) {
//         return;
//     }
//     if(fact_memo[val] == 0) {
//         vv.PB(val);
//         return;
//     }
//     vv.PB(fact_memo[val]);
//     frec(val / fact_memo[val], vv);
// }

vector<int> frecv;
void get_fact(int val, vector<PII> &vv) {
    vv.clear();
    frecv.clear();
    // frec(val, frecv);
    while(val >= 2) {
        if(fact_memo[val] == 0) {
            frecv.PB(val);
            break;
        }
        frecv.PB(fact_memo[val]);
        val /= fact_memo[val];
    }



    sort(frecv.begin(), frecv.end());
    
    int prev = -1;
    int cnt = 0;
    for(int val: frecv) {
        if(val == prev) {
            cnt++;
            continue;
        }
        if(prev != -1) {
            vv.PB({prev, cnt});
            cnt = 0;
        }
        cnt++;
        prev = val;
    }
    if(cnt) {
        vv.PB({prev, cnt});
    }

}


/****************************short sieve and prime fact generate end***********************************/

/****************************divisor generation start***********************************/
 
vector<int> divisors;
void gen_divisors(int x) {
    // prime_fact(x);
    get_fact(x, fact);


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

int c, d, x;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;

    init_fact_sieve(20000010);

    // FOR(i, 1, 100) {
    //     cout << i << " : " << fact_memo[i] << endl;
    // }
    // return 0;

    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> c >> d >> x;
        gen_divisors(x);
        LL ans = 0;
        for(int div: divisors) {
            int ab = d + (x / div);
            if(ab % c) {
                continue;
            }
            ab /= c;
            get_fact(ab, fact);

            // cout << ab << " : ";
            // for(PII val: fact) {
            //     cout << "(" << val.F << " " << val.S << ") ";
            // }
            // cout << "\n";

            // gcd(a, b) has to be 1
            LL foo = 1;
            for(PII val: fact) {
                foo *= 2;
            }
            ans += foo;
            // cout << foo;
        }
        cout << ans << "\n";
    }

    return 0;
}
/**
*/