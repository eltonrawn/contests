#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string r, b;


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        cin >> r >> b;
        int cnt_r = 0;
        int cnt_b = 0;
        for(int i = 0; i < n; i++) {
            if(r[i] > b[i]) {
                cnt_r++;
            }
            if(r[i] < b[i]) {
                cnt_b++;
            }
        }
        if(cnt_b == cnt_r) {
            cout << "EQUAL" << endl;
        }
        if(cnt_b < cnt_r) {
            cout << "RED" << endl;
        }
        if(cnt_b > cnt_r) {
            cout << "BLUE" << endl;
        }
    }
    return 0;
}
/**
*/
