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
#define MOD 1000000007
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL dp[MX];

LL fact(LL pos) {
    if(pos == 0) {
        return 1;
    }
    if(dp[pos] != -1) {
        return dp[pos];
    }
    return dp[pos] = (pos * fact(pos - 1)) % MOD;
}

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

LL num_of_unq_perm(vector<int> &vv) {
    /// careful about this sorting, as main vector from caller version will also get sorted
    sort(vv.begin(), vv.end());
    LL ans = fact(vv.size());
    for(int i = 0; i < (int)vv.size(); i++) {
        int j = i;
        while((j < (int)vv.size()) && vv[i] == vv[j]) {
            j++;
        }
        ans *= mod_inv(fact(j - i));
        ans %= MOD;
        i = j - 1;
    }
    return ans;
}

LL num_of_unq_perm_cnt(vector<int> &cnts) {
    LL ans = 0;
    LL sum = 0;
    FOR(i, 0, (int)cnts.size() - 1) {
        sum += cnts[i];
    }
    
    ans = fact(sum);
    FOR(i, 0, (int)cnts.size() - 1) {
        ans *= mod_inv(fact(cnts[i]));
        ans %= MOD;
    }
    return ans;
}

LL stars_and_bars(int stars, int bars) {
    if(stars == 0 || bars == 0) {
        return 1;
    }
    vector<int> cnts;
    cnts.PB(stars);cnts.PB(bars);
    return num_of_unq_perm_cnt(cnts);
}

int n;
LL ara[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    MEM(dp, -1);
    cin >> n;
    LL sum = 0;
    FOR(i, 1, n) {
        cin >> ara[i];
        sum += ara[i];
    }
    if(sum % n) {
        cout << 0 << endl;
        return 0;
    }
    LL single = sum / n;
    
    // LL less = 0, eq = 0, boro = 0;
    vector<int> less, eq, boro, noteq;
    FOR(i, 1, n) {
        noteq.PB(ara[i]);
        if(ara[i] < single) {
            less.PB(ara[i]);
        }
        else if(ara[i] > single) {
            boro.PB(ara[i]);
        }
        else {
            eq.PB(ara[i]);
            noteq.pop_back();
        }
    }
    LL ans = 1;
    if(less.size() == 1 || boro.size() == 1) {
        ans = num_of_unq_perm(noteq);
    }
    else if(noteq.size()) {
        ans = num_of_unq_perm(less) * num_of_unq_perm(boro) * 2;
        ans %= MOD;
    }
    ans *= num_of_unq_perm(eq); ans %= MOD;

    ans *= stars_and_bars(eq.size(), noteq.size()); ans %= MOD;
    
    cout << ans << endl;
    return 0;
}
/**
 * tags: modulo inverse, stars and bars, number of unique permutation, combinatorics
*/
