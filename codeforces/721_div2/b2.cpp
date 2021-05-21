#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str;

void palindrome_ans(int zcnt) {
    
    if(zcnt == 1 || (zcnt % 2) == 0) {
        cout << "BOB" << endl;
    }
    else {
        cout << "ALICE" << endl;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> str;
        bool is_palin = 1;
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            if(str[i] != str[j]) {
                is_palin = 0;
                break;
            }
        }
        int zcnt = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '0') {
                zcnt++;
            }
        }
        if(is_palin) {
            palindrome_ans(zcnt);
            continue;
        }
        if(zcnt == 2 && n % 2 && str[n / 2] == '0') {
            cout << "DRAW" << endl;
            continue;
        }
        cout << "ALICE" << endl;
    }
    return 0;
}
/**
*/
