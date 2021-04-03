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

int n;
string str, a, b;
vector<int> zz;

void populate_one() {
    bool chk = 0;

    FOR(i, 0, n - 1) {
        if(!zz.empty() && (i == zz[0] - 1 || i == zz.back() + 1)) {
            continue;
        }
        if(str[i] == '1') {
            if(chk == 0) {
                a[i] = '(';
                b[i] = '(';
            }
            else {
                a[i] = ')';
                b[i] = ')';
            }

            chk = !chk;
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> str;
        int zero = 0;
        zz.clear();
        a = "";
        b = "";

        FOR(i, 0, n - 1) {
            if(str[i] == '0') {
                zero++;
                zz.PB(i);
            }
            a += "Z";
            b += "Z";
        }
        if(n % 2 || zero % 2) {
            cout << "NO\n";
            continue;
        }

        if(zz.empty()) {
            /// handle it
            populate_one();
            cout << "YES\n";
            cout << a << "\n";
            cout << b << "\n";
            continue;
        }

        if(zz[0] == 0 || zz.back() == n - 1) {
            cout << "NO\n";
            continue;
        }

        bool chk = 0;

        FOR(i, 0, n - 1) {
            if(str[i] == '0') {
                if(chk == 0) {
                    a[i] = '(';
                    b[i] = ')';
                }
                else {
                    a[i] = ')';
                    b[i] = '(';
                }

                chk = !chk;
            }
        }
        a[ zz[0] - 1 ] = '(';
        b[ zz[0] - 1 ] = '(';

        a[ zz.back() + 1 ] = ')';
        b[ zz.back() + 1 ] = ')';

        populate_one();
        cout << "YES\n";
        cout << a << "\n";
        cout << b << "\n";
        
    }
    return 0;
}
/**
*/
