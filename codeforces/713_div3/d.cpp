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
LL ara[MX];
LL sum;
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        n += 2;
 
        sum = 0;
        FOR(i, 0, n - 1) {
            cin >> ara[i];
            sum += ara[i];
        }
        sort(ara, ara + n);
        sum -= ara[n - 1];
 
        if(sum - ara[n - 2] == ara[n - 2]) {
            FOR(i, 0, n - 3) {
                cout << ara[i] << " ";
            }
            cout << "\n";
            continue;
        }
        int pos = -1;
        FOR(i, 0, n - 2) {
            if(sum - ara[i] == ara[n - 1]) {
                pos = i;
                break;
            }
        }
 
        if(pos == -1) {
            cout << -1 << "\n";
            continue;
        }
        FOR(i, 0, n - 2) {
            if(i == pos) {
                continue;
            }
            cout << ara[i] << " ";
        }
        cout << "\n";
        // cout << ara[pos] << "\n";
    }
    return 0;
}
/**
*/
