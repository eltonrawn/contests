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

int h, m;

bool trans(char &ch) {
    if(ch == '0' || ch == '1' || ch == '8') {
        return 1;
    }
    if(ch == '2') {
        ch = '5';
        return 1;
    }
    if(ch == '5') {
        ch = '2';
        return 1;
    }
    return 0;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> h >> m;
        char a, b;
        cin >> a >> b;
        char tmp;cin >> tmp;
        char c, d;
        cin >> c >> d;

        int ab = ((a - '0') * 10) + (b - '0');
        int cd = ((c - '0') * 10) + (d - '0');
        

        for(int i = 0;; i++) {
            if(i != 0) {
                cd++;
                if(cd == m) {
                    cd = 0;
                    ab++;
                }

                if(ab == h) {
                    ab = 0;
                }
            }
            
            
            // cout << ab << " " << cd << endl;
            // break;
            a = (ab % 10) + '0';
            b = (ab / 10) + '0';
            c = (cd % 10) + '0';
            d = (cd / 10) + '0';

            if(!trans(a)) continue;
            if(!trans(b)) continue;
            if(!trans(c)) continue;
            if(!trans(d)) continue;

            int uab = ((c - '0') * 10) + (d - '0');
            int ucd = ((a - '0') * 10) + (b - '0');
            if(uab < h && ucd < m) {
                if(ab / 10 == 0) {
                    cout << 0 << ab;
                }
                else {
                    cout << ab;
                }
                cout << ":";
                if(cd / 10 == 0) {
                    cout << 0 << cd;
                }
                else {
                    cout << cd;
                }
                cout << "\n";
                break;
            }
            
        }

        
    }
    return 0;
}
/**
*/
