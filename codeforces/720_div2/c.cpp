#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 10010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;

int ask_question(int tp, int p1, int p2, int x) {
    cout << "? " << tp << " " << p1 << " " << p2 << " " << x << endl;
    int val; cin >> val;
    if(val == -1) exit(0);
    return val;
}

int reply[SZ], ans[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // int n = 6;

    // cout << "tp1 " << n - 1 << " " << n << endl;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i + 1; j <= n; j++) {
    //         cout << "tp1 " << i << " " << j << " : " << max(min(n - 1, i), min(n, j)) << endl;
    //         cout << "tp1 " << j << " " << i << " : " << max(min(n - 1, j), min(n, i)) << endl;
    //         cout << endl;
    //     }
    // }

    // cout << endl << endl;

    // cout << "tp2 " << 1 << " " << 2 << endl;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i + 1; j <= n; j++) {
    //         cout << "tp2 " << i << " " << j << " : " << min(max(1, i), max(2, j)) << endl;
    //         cout << "tp2 " << j << " " << i << " : " << min(max(1, j), max(2, i)) << endl;
    //         cout << endl;
    //     }
    // }


    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;

        int n_pos = 0;
        for(int i = 2; i <= n; i += 2) {
            int rr = ask_question(1, i - 1, i, n - 1);
            if(rr == n) {
                n_pos = i; break;
            }
            else if(rr == n - 1) {
                rr = ask_question(1, i, i - 1, n - 1);
                if(rr == n) {
                    n_pos = i - 1; break;
                }
            }
        }
        if(!n_pos) n_pos = n;

        for(int i = 1; i <= n; i++) {
            if(i == n_pos) {ans[i] = n; continue;}
            ans[i] = ask_question(2, i, n_pos, 1);
        }
        cout << "! ";
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
