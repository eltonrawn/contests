#include<bits/stdc++.h>

using namespace std;

// #define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/****************************prime fact range start***********************************/


int fact_memo[30000010 + 10];
vector<PII> fact;

void init_fact_sieve(int limit) {
    memset(fact_memo, 0, sizeof(fact_memo));
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
            frecv.push_back(val);
            break;
        }
        frecv.push_back(fact_memo[val]);
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
            vv.push_back({prev, cnt});
            cnt = 0;
        }
        cnt++;
        prev = val;
    }
    if(cnt) {
        vv.push_back({prev, cnt});
    }

}
/****************************prime fact range stop***********************************/

int c, d, x;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    init_fact_sieve(20000010);
    get_fact(100, fact);

    return 0;
}
/**
 * tags: number theory
*/