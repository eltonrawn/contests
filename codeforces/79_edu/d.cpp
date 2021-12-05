#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL bm(LL base, LL power) {    //bm represents bigmod
    if(power == 0)  {
        return 1;
    }
    if(power % 2 == 0)  {
        LL ret = bm(base, power / 2);
        return (ret * ret) % MOD;
    }
    else    {
        return (base * bm(base, power - 1)) % MOD;
    }
}
 
LL mod_inv(LL num)   {
    //fermat's little theorem
    //modu should be prime to use fermat
    return bm(num, MOD - 2);
}

int n;
vector<int> vv[1000010];
map<int, int> mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cout << ((7 * mod_inv(8)) % MOD) << endl;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int tmp; cin >> tmp;
            vv[i].push_back(tmp);
            mp[tmp]++;
        }
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            // ans += (1 / n) * (1 / vv[i].size()) * (mp[vv[i][j]] / n);
            LL tmp = 1;
            tmp *= mod_inv(n); tmp %= MOD;
            tmp *= mod_inv(vv[i].size()); tmp %= MOD;
            tmp *= mp[vv[i][j]]; tmp %= MOD;
            tmp *= mod_inv(n); tmp %= MOD;
            ans = ans + tmp; ans %= MOD;
            // cout << "(1 / " << n << ") * " << "(1 / " << vv[i].size() << ") * " << "(" << mp[vv[i][j]] << " / " << n << ")" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
/**
start: 8:27 pm
end: 9:10 pm
duration: 43 mins
*/
