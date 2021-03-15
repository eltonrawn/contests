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

LL ext_gcd (LL A, LL B, LL *X, LL *Y){
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L (LCM(m1, m2, ....))
*/
pair<LL, LL> chinese_remainder_theorem(vector<LL> A, vector<LL> M) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    LL a1 = A[0];
    LL m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        LL a2 = A[i];
        LL m2 = M[i];
 
        LL g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        LL p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        LL mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        LL x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}

void visualize_a_case(int n, int m) {
    int a = 1;
    int b = 1;
    int lcmm = n / __gcd(n, m) * m;
    for(int i = 1; i <= 2 * lcmm; i++) {
        if(a == n && b == m) {
            cout << "------------------------------------------------>";
        }
        cout << i << " : " << a << " " << b << endl;
        
        a++;
        b++;
        if(a > n) {
            a = 1;
        }
        if(b > m) {
            b = 1;
        }
    }
}

LL n, m;
LL k;
LL a[500010], b[500010];
vector<LL> match;
LL lcmm;

bool chk(LL pos) {
    LL mism_loc = lcmm - match.size();
    LL steps = (pos / lcmm);
    LL mism_glob = steps * mism_loc;
    if(mism_glob >= k) {
        return 1;
    }
    LL covered = steps * lcmm;
    if(pos - covered == 0) {
        return 0;
    }

    int pp = lower_bound(match.begin(), match.end(), pos - covered) - match.begin();
    if(pp == match.size()) {
        pp--;
    }
    if(pp >= 0 && match[pp] > pos - covered) {
        pp--;
    }
    pp++;
    // cout << mism_glob << " " << (pos - covered) << " " << pp << " " << mism_glob + (pos - covered) - pp << "\n";
    if(mism_glob + (pos - covered) - pp >= k) {
        return 1;
    }
    return 0;
}

map<int, int> mp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> m >> k;
    // visualize_a_case(n, m);
    FOR(i, 1, n) {
       cin >> a[i];
       mp[ a[i] ] = i;
    }
    FOR(i, 1, m) {
        cin >> b[i];
        int pp = mp[ b[i] ];
        if(pp == 0) {
            continue;
        }
        PLL foo = chinese_remainder_theorem({pp, i}, {n, m});
        if(foo.F < 0) {
            continue;
        }
        if(foo.F == 0) {
            foo.F = foo.S;
        }
        match.PB(foo.F);
        // cout << b[i] << " " << foo.F << endl;
    }
    lcmm = n / __gcd(n, m) * m;
    // cout << "lcm : " << lcmm << endl;
    sort(match.begin(), match.end());

    // chk(61);
    // return 0;

    LL lo = 1, hi = LLONG_MAX;
    while(lo < hi) {
        LL mid = lo + ((hi - lo) / 2LL);
        if(chk(mid)) {
            /// returns 1 if mismatch >= k
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
    return 0;
}
/**
 * tags: crt, chinese remainder theorem
*/
