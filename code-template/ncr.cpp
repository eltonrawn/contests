#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL fact[SZ], rfact[SZ];

long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
}

LL ncr(int n, int r) {
    return fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
}

void init_ncr() {
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < SZ; i++) {
        fact[i] = i * fact[i - 1] % MOD;
        rfact[i] = inv(i, MOD) * rfact[i - 1] % MOD;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    init_ncr();
    cout << ncr(420, 69) << endl;

    return 0;
}
/**
 * tags: ncr
*/
