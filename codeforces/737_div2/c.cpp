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

int n, k;

bool all_poss = 0;
LL all_poss_pre;
LL all_poss_func() {
    if(all_poss) return all_poss_pre;
    all_poss = 1;
    all_poss_pre = 1;
    for(int i = 1; i <= n; i++) {
        all_poss_pre *= 2;
        all_poss_pre %= MOD;
    }
    return all_poss_pre;
}

bool place_even = 0;
LL place_even_pre;
LL place_even_func() {
    if(place_even) return place_even_pre;
    place_even = 1;
    LL ans = 0;
    for(int i = 0; i < n; i += 2) {
        ans += ncr(n, i);
    }
    place_even_pre = ans % MOD;
    return place_even_pre;
}

LL dp[SZ][2];

LL func(int pos, bool is_bigger) {
    if(pos == k) return 1;
    if(dp[pos][is_bigger] != -1) return dp[pos][is_bigger];
    LL ans = 0;
    if(is_bigger == 0) {
        /// place even 1
        // for(int i = 0; i < n; i += 2) {
        //     ans += ncr(n, i) * func(pos + 1, 0);
        // }
        ans += place_even_func() * func(pos + 1, 0) % MOD;
        /// place all
        if(n % 2) {
            ans += func(pos + 1, 0);
        }
        else {
            ans += func(pos + 1, 1);
        }
    }
    else {
        /// place anything in n places 2 ** n
        ans = all_poss_func() * func(pos + 1, 1) % MOD;
    }
    ans %= MOD;
    return dp[pos][is_bigger] = ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_ncr();
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        all_poss = 0; place_even = 0;
        cout << func(0, 0) << endl;;
    }
    return 0;
}
/**
 * tags: ncr
*/
