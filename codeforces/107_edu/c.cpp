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

int n, q;
int col[MX];
set<int> st[55];
int yoo[55];
int mv[55];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> q;
    MEM(yoo, 0);
    FOR(i, 1, n) {
        cin >> col[i];
        // st[ col[i] ].insert(i);
        if(yoo[ col[i] ] == 0) {
            yoo[ col[i] ] = i;
            // cout << col[i] << " : " << i << endl;
        }
    }
    FOR(kiki, 1, q) {
        int qq;
        cin >> qq;
        // cout << (*st[qq].begin()) + mv[q];
        cout << yoo[ qq ] << " ";
        FOR(j, 1, 50) {
            if(yoo[j] == -1) {
                continue;
            }
            if(j != qq &&  yoo[j] < yoo[qq]) {
                yoo[j]++;
            }
        }
        yoo[qq] = 1;
    }
    cout << endl;
    return 0;
}
/**
*/
