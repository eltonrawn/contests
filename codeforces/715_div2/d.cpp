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
string str[3];
int freq[3][3];
string ans;

void func(int pos1, int pos2, char ch, int p1, int p2) {
    // if(p1 == str[pos1].size() && p2 == str[pos2].size()) {
    //     return;
    // }
    // cout << p1 << " " << p2 << endl;
    if((p1 < str[pos1].size()) && (p2 < str[pos2].size()) && (str[pos1][p1] == str[pos2][p2])) {
        ans += str[pos1][p1];
        func(pos1, pos2, ch, p1 + 1, p2 + 1);
        return;
    }
    if(((p2 == str[pos2].size()) || (str[pos1][p1] != ch)) && (p1 < str[pos1].size())) {
        ans += str[pos1][p1];
        func(pos1, pos2, ch, p1 + 1, p2);
        return;
    }
    if(((p1 == str[pos1].size()) || (str[pos2][p2] != ch)) && (p2 < str[pos2].size())) {
        ans += str[pos2][p2];
        func(pos1, pos2, ch, p1, p2 + 1);
        return;
    }


    // for(int i1 = 0, i2 = 0; i1 < str[pos1].size() && i2 < str[pos2].size();) {
    //     if() {

    //     }
    // }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(pos, 0, 2) {
            cin >> str[pos];
        }
        MEM(freq, 0);
        FOR(pos, 0, 2) {
            FOR(i, 0, (2 * n) - 1) {
                freq[pos][ str[pos][i] - '0' ]++;
            }
        }
        
        FOR(i, 0, 1) {
            vector<int> foo;
            FOR(pos, 0, 2) {
                if(freq[pos][i] >= n) {
                    foo.PB(pos);
                }
            }
            if(foo.size() >= 2) {
                ans = "";
                // cout << "pos : " << foo[0] << ' ' << foo[1] << endl;
                func(foo[0], foo[1], i + '0', 0, 0);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
