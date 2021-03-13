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

int n, m;
string str[510];

void print_str() {
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            cout << str[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);tt
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        FOR(i, 0, n - 1) {
            cin >> str[i];
        }

        // print_str();
        vector<int> pps;

        if(m % 3 == 0 || (m + 1) % 3 == 0) {
            for(int i = 1; i < m; i += 3) {
                pps.PB(i);
            }
        }
        else {
            for(int i = 0; i < m; i += 3) {
                pps.PB(i);
            }
        }

        for(int pos: pps) {
            FOR(i, 0, n - 1) {
                str[i][pos] = 'X';
            }
            
        }

        for(int pos: pps) {
            bool chk = 1;
            for(int i = 0; i < n && (pos - 2 >= 0) && chk; i++) {
                if(str[i][pos - 1] == 'X') {
                    str[i][pos - 2] = 'X';
                    chk = 0;
                }
            }
            for(int i = 0; i < n && (pos - 2 >= 0) && chk; i++) {
                if(str[i][pos - 2] == 'X') {
                    str[i][pos - 1] = 'X';
                    chk = 0;
                }
            }
            if(chk && (pos - 2 >= 0)) {
                str[0][pos - 1] = 'X';
                str[0][pos - 2] = 'X';
            }

        }
        print_str();
    }
    return 0;
}
/**
*/
