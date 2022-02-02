#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/****************************prime fact range start***********************************/

int fact_memo[15000010];
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

int n;
int ara[SZ];
map<int, int> mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_fact_sieve(15000001);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int gcd = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            gcd = __gcd(gcd, ara[i]);
        }
        for(int i = 1; i <= n; i++) {
            ara[i] /= gcd;
        }

        mp.clear();
        for(int i = 1; i <= n; i++) {
            // prime_fact(ara[i]);
            get_fact(ara[i], fact);
            for(PII ff: fact) {
                mp[ff.first]++;
            }
        }

        int ans = INT_MAX;
        for(auto it: mp) {
            ans = min(ans, n - it.second);
        }

        cout << (ans == INT_MAX ? -1: ans) << endl;

    // }
    return 0;
}
/**
*/
