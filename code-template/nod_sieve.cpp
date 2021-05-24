#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 2000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int n;
int no_div[SZ];

void nod() {
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            no_div[j]++;
}

/**
 * 
 * tags: number of divisors, nod, sieve
*/