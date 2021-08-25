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

LL n, l, r;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_ncr();
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        LL a, b;
        cin >> n >> a >> b;
        LL diffa = 1 - a;
        LL diffb = b - n;
        LL mxdiff = max(diffa, diffb);
        LL mndiff = min(diffa, diffb);
        l = 1 - mxdiff;
        r = n + mndiff;
//        cout << "lr : " << l << " " << r << endl;
 
        LL ans = 0;
 
        mndiff = 0;
        // mxdiff = 0;
        int cnt = 0;
 
        for(int i = max(l, 1 - (r - 1)); i < 1; i++) {
            cnt++;
            /// using range i to r; thus fixing left
            int diff = 1 - i;
            int pos_ri_range = min(r - diff, n);
            // if(mxdiff == 0) mxdiff = diff;
            // cout << "fir " << diff << " : " << pos_ri_range << endl;
            if(pos_ri_range == n) {mndiff = diff; break;}
            if(n % 2 == 0) {
                if(pos_ri_range >= n / 2) {
                    ans += ncr(pos_ri_range, n / 2);
                    if(ans >= MOD) ans -= MOD;
                }
            }
            else {
                if(pos_ri_range >= n / 2) {
                    ans += ncr(pos_ri_range, n / 2);
                    if(ans >= MOD) ans -= MOD;
                }
                if(pos_ri_range >= (n + 1) / 2) {
                    ans += ncr(pos_ri_range, (n + 1) / 2);
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
 
//        cout << "mn_diff : " << mndiff << " " << mxdiff << endl;
        if(n % 2 == 0) {
            ans += mndiff * ncr(n, n / 2) % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        else {
            ans += mndiff * ncr(n, n / 2)% MOD;
            if(ans >= MOD) ans -= MOD;
            ans += mndiff * ncr(n, (n + 1) / 2) % MOD;
            if(ans >= MOD) ans -= MOD;
        }

        for(int diff = n - l; diff > (1 - l); diff--) {
            cnt++;
            int pos_le_range = max(l + diff, 1LL);
            int pos_ri_range = min(r - diff, n);
            if(pos_ri_range == pos_le_range - 1 && (pos_ri_range >= n / 2) && (n - pos_le_range + 1 >= n / 2)) {
                ans++;
                if(ans >= MOD) ans -= MOD;
                continue;
            }
            if(pos_ri_range < pos_le_range) continue;
            if(n % 2 == 0) {
                if(pos_ri_range >= n / 2) {
                    int take = n / 2;
                    take -= pos_le_range - 1;
                    ans += ncr(pos_ri_range - pos_le_range + 1, take);
                    if(ans >= MOD) ans -= MOD;
                }
            }
            else {
                if(pos_ri_range >= n / 2) {
                    int take = n / 2;
                    take -= pos_le_range - 1;
                    ans += ncr(pos_ri_range - pos_le_range + 1, take);
                    if(ans >= MOD) ans -= MOD;
                }
                if(pos_ri_range >= (n + 1) / 2) {
                    int take = (n + 1) / 2;
                    take -= pos_le_range - 1;
                    ans += ncr(pos_ri_range - pos_le_range + 1, take);
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
        // cout << "cnt : " << cnt << endl;
        cout << ans << endl;
    }
    return 0;
}
/**
*/