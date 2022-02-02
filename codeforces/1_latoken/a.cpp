#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string str[110];
string tmp[110];

bool solve(bool cc) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cc) {
                if((i + j) % 2) {
                    tmp[i][j] = 'W';
                }
                else {
                    tmp[i][j] = 'R';
                }
            }
            else {
                if((i + j) % 2) {
                    tmp[i][j] = 'R';
                }
                else {
                    tmp[i][j] = 'W';
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(str[i][j] != '.' && tmp[i][j] != str[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void print_it() {
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << tmp[i][j];
        }
        cout << endl;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
            tmp[i] = str[i];
        }
        if(solve(0)) {
            print_it(); continue;
        }
        if(solve(1)) {
            print_it(); continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
/**
*/
