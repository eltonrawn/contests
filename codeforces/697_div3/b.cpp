#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int make = 0;
        bool chk = 0;
        while(make <= n) {
            if((n - make) % 2021 == 0) {
                chk = 1;break;
            }
            make += 2020;
        }
        if(chk) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
/**
*/
