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


/****************************prime fact range start***********************************/


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
/****************************prime fact range start***********************************/

int c, d, x;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;

    init_fact_sieve(20000010);
    get_fact(100, fact);

    return 0;
}
/**
*/