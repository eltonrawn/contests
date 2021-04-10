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
string ara[410];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 0, n - 1) {
            cin >> ara[i];
        }
        
        vector<PII> vv;
        FOR(i, 0, n - 1) {
            FOR(j, 0, n - 1) {
                if(ara[i][j] == '*') {
                    vv.PB({i, j});
                }
            }
        }

        if(vv[0].S == vv[1].S) {
            if(vv[0].S != n - 1) {
                ara[ vv[0].F ][ vv[0].S + 1 ] = '*';
                ara[ vv[1].F ][ vv[1].S + 1 ] = '*';
            }
            else {
                ara[ vv[0].F ][ vv[0].S - 1 ] = '*';
                ara[ vv[1].F ][ vv[1].S - 1 ] = '*';
            }
        }
        else if(vv[0].F == vv[1].F) {
            if(vv[0].F != n - 1) {
                ara[ vv[0].F + 1 ][ vv[0].S ] = '*';
                ara[ vv[1].F + 1 ][ vv[1].S ] = '*';
            }
            else {
                ara[ vv[0].F - 1 ][ vv[0].S ] = '*';
                ara[ vv[1].F - 1 ][ vv[1].S ] = '*';
            }
        }
        else {
            int mnx = min(vv[0].F, vv[1].F);
            int mxx = max(vv[0].F, vv[1].F);

            int mny = min(vv[0].S, vv[1].S);
            int mxy = max(vv[0].S, vv[1].S);

            ara[ mnx ][ mny ] = '*';
            ara[ mnx ][ mxy ] = '*';
            ara[ mxx ][ mny ] = '*';
            ara[ mxx ][ mxy ] = '*';
        }

        FOR(i, 0, n - 1) {
            FOR(j, 0, n - 1) {
                cout << ara[i][j];
            }
            cout << "\n";
        }
        // cout << "\n";

    }
    return 0;
}
/**
*/
