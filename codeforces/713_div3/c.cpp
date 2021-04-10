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
int a, b;
string str;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> a >> b >> str;
        n = a + b;

        FOR(i, 0, n - 1) {
            if(str[i] == '0') {
                a--;
            }
            if(str[i] == '1') {
                b--;
            }
        }
        
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            if(str[i] == '?' && str[j] == '?') {
                continue;
            }
            if(str[i] == '?') {
                if(str[j] == '0') {
                    a--;
                }
                else {
                    b--;
                }
                str[i] = str[j];
                continue;
            }
            if(str[j] == '?') {
                if(str[i] == '0') {
                    a--;
                }
                else {
                    b--;
                }
                str[j] = str[i];
                continue;
            }

            if(str[i] != str[j]) {
                a = -1;
                break;
            }
        }
        if(a < 0 || b < 0) {
            // cout << "hi1\n";
            cout << -1 << endl;
            continue;
        }
        // cout << a << " " << b << endl;
        bool chk = 1;
        for(int i = 0, j = n - 1; i <= j; i++, j--) {
            if(i == j) {
                if(str[i] != '?') {
                    continue;
                }
                if(a) {
                    str[i] = '0';
                    a--;
                }
                else if(b) {
                    str[i] = '1';
                    b--;
                }
                else {
                    chk = 0;
                }
                continue;
            }
            if(str[i] == '?' && str[j] == '?') {
                if(a >= 2) {
                    str[i] = str[j] = '0';
                    a -= 2;
                }
                else if(b >= 2) {
                    str[i] = str[j] = '1';
                    b -= 2;
                }
                else {
                    chk = 0;
                    break;
                }
            }
        }
        if(!chk || a || b) {
            // cout << chk << " " << a << " " << b << " " << "hi2\n";
            cout << -1 << endl;
            continue;
        }
        cout << str << endl;
    }
    return 0;
}
/**
*/
