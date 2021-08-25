#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int x1, g1;
int x2, y2;
int x3, y3;


int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> x1 >> g1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        int cc = 0;
        if(g1 == y2 && y2 == y3 && ((x1 < x3 && x3 < x2) || (x2 < x3 && x3 < x1))) {
            cc = 2;
        }
        if(x1 == x2 && x2 == x3 && ((g1 < y3 && y3 < y2) || (y2 < y3 && y3 < g1))) {
            cc = 2;
        }
        cout << abs(x2 - x1) + abs(y2 - g1) + cc << endl;
    }
    return 0;
}
/**
*/
