#include<bits/stdc++.h>

using namespace std;

// #define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


/****************************prime fact range start***********************************/


int fact_memo[1000010 + 10];
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
/****************************prime fact range start***********************************/

int MOD;
int n;
int ara[SZ], nara[SZ];
int freq[1000010][20];


int mod(LL vv) {
    if(vv >= MOD) vv -= MOD;
    return vv;
}

void inc_freq(int vv) {
    get_fact(vv, fact);
    for(PII val: fact) {
        for(int j = 1; j <= val.second; j++)
            freq[val.first][j]++;
    }
}

void dec_freq(int vv) {
    get_fact(vv, fact);
    for(PII val: fact) {
        for(int j = 1; j <= val.second; j++)
            freq[val.first][j]--;
    }
}

void init_freq(int vv) {
    get_fact(vv, fact);
    for(PII val: fact) {
        for(int j = 1; j <= val.second; j++)
            freq[val.first][j] = 0;
    }
}

int get_gcd(int vv, int step) {
    get_fact(vv, fact);
    int ans = 1;
    for(PII val: fact) {
        for(int j = val.second; j >= 1; j--) {
            if(freq[val.first][j] == step) {
                for(int k = 1; k <= j; k++) ans *= val.first;
                break;
            }
        }
    }
    return ans;
}

bool chk(int step) {
    // cout << "step : " << step << endl;
    int k = step + 1;
    for(int i = 0; i < n; i++) {
        init_freq(ara[i]);
    }

    for(int i = 0; i < k - 1; i++) {
        inc_freq(ara[i]);
    }
    inc_freq(ara[n - 1]);

    for(int i = k - 1; i < n; i++) {
        dec_freq(ara[mod(i - k + MOD)]);
        inc_freq(ara[i]);
        nara[i] = get_gcd(ara[i], k);
    }
    for(int i = 0; i < k - 1; i++) {
        dec_freq(ara[mod(i - k + MOD)]);
        inc_freq(ara[i]);
        nara[i] = get_gcd(ara[i], k);
    }

    // cout << k << " : ";
    // for(int i = 0; i < n; i++) cout << nara[i] << " ";
    // cout << endl;

    for(int i = 1; i < n; i++) {
        if(nara[i] != nara[i - 1]) return 0;
    }
    return 1;

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init_fact_sieve(1000010);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        MOD = n;
        for(int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(chk(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
    return 0;
}
/**
*/
