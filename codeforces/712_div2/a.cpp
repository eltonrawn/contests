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

string str;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> str;
        int pos = -1;
        FOR(i, 0, (int)str.size() - 1) {
            if(str[i] != 'a') {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        int pos2 = -1;

        for(int i = 0, j = str.size() - 1; i <= j; i++, j--) {
            if(str[i] != 'a') {
                pos2 = j;
                break;
            }
            if(str[j] != 'a') {
                pos2 = i - 1;
                break;
            }
        }
        if(pos2 == -1) {
            cout << 'a';
        }
        for(int i = 0; i < (int)str.size(); i++) {
            cout << str[i];
            if(i == pos2) {
                cout << 'a';
            }
        }
        cout << "\n";

    }
    return 0;
}
/**
*/
