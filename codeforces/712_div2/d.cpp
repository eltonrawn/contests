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
vector<PII> fir, sec;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if((i + j) % 2) {
                fir.PB({i, j});
            }
            else {
                sec.PB({i, j});
            }
        }
    }

    FOR(i, 1, n * n) {
        int guess;
        cin >> guess;
        if(guess != 2) {
            if(!sec.empty()) {
                cout << 2 << " ";
                cout << sec.back().F << " " << sec.back().S << endl;
                sec.pop_back();
                continue;
            }
        }
        if(guess != 1) {
            if(!fir.empty()) {
                cout << 1 << " ";
                cout << fir.back().F << " " << fir.back().S << endl;
                fir.pop_back();
                continue;
            }
        }

        if(!sec.empty()) {
            cout << 3 << " ";
            cout << sec.back().F << " " << sec.back().S << endl;
            sec.pop_back();
            continue;
        }
        if(!fir.empty()) {
            cout << 3 << " ";
            cout << fir.back().F << " " << fir.back().S << endl;
            fir.pop_back();
            continue;
        }

    }

    return 0;
}
/**
*/
