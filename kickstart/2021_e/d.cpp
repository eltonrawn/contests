#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n;

long double get_all_poss() {
    /// factorial
    long double ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

long double fact(LL num) {
    long double ans = 1;
    for(int i = 1; i <= num; i++) {
        ans *= (long double)i;
    }
    return ans;
}

long double process_under_ten() {
    int taken = 0;
    vector<int> ara;
    for(int i = 1; i <= n; i++) ara.push_back(i);
    do {
        int past = ara[0];
        taken++;
        for(int val: ara) {
            if(val > past) {
                past = val; taken++;
            }
        }
    } while (next_permutation(ara.begin(), ara.end()));
    return ((long double)taken) / get_all_poss();
}

long double process_brute() {
    long double ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            ans += (((long double)j) * fact(j - 1) * fact(n - (j + 1))) / fact(n);
        }
    }
    return ans;
}

long double nono[10000010];

void foo() {
    long double ans = 0;
    for(int i = 1; i < 10000010; i++) {
        ans += (1.0 / (long double)i);
        nono[i] = ans;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        // double ans;
        cin >> n;
        // for(int i = 1; i < n; i++) {

        // }
        cout << "Case #" << tt << ": ";
        // cout << process_under_ten() << " ";
        // cout << fixed << setprecision(9) << process_brute() << endl;
        // cout << fixed << setprecision(9) << foo() << endl;
        // cout << foo() << " ";
        // cout << fixed << setprecision(9) << log(n)+0.5772156649 << endl;
        // cout << fixed << setprecision(9) << process_under_ten() << endl;
        foo();
        if(n < 10000010) {
            cout << fixed << setprecision(9) << nono[n] << endl;
        }
        else {
            cout << fixed << setprecision(9) << (long double)log(n)+(long double)0.5772156649 << endl;
        }
        
    }
    return 0;
}
/**
 * tags: harmonic series, expected value, probability
*/
