#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str[9];

int col_filled[9], sub[20], add[20];

int bt(int row) {
    if(row == 8) return 1;
    int ans = 0;
    for(int i = 0; i < 8; i++) {
        if(str[row][i] == '*' || col_filled[i] || sub[row - i + 8] || add[row + i]) continue;
        col_filled[i] = 1; sub[row - i + 8] = 1; add[row + i] = 1;
        ans += bt(row + 1);
        col_filled[i] = 0; sub[row - i + 8] = 0; add[row + i] = 0;
    }
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 8; i++) {
        cin >> str[i];
    }
    cout << bt(0) << endl;

    // for(int i = 0; i < 8; i++) {
    //     for(int j = 0; j < 8; j++) {
    //         cout << i + j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 0; i < 8; i++) {
    //     for(int j = 0; j < 8; j++) {
    //         cout << i - j << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}
/**

  1 2 3 4 5 6 7 8
1     *         *
2   *   *     *
3           *
4         *
5
6
7
8

*/
