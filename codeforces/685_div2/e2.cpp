#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int xx[SZ], ans[SZ];
int foo[2];
vector<int> vv[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    int mxbit;
    for(int j = 0; j < 20; j++) {
        if((n - 1) & (1 << j)) {
            mxbit = j;
        }
    }

    vector<int> candidates;
    int same_first_bit;
    for(int i = 2; i <= n; i++) {
        /// n - 1
        cout << "XOR " << 1 << " " << i << endl;
        cin >> xx[i];
        if(xx[i] == 0 || xx[i] == 1) foo[xx[i]] = i;
        if((xx[i] & (1 << 0)) == 0) same_first_bit = i;
        vv[xx[i]].push_back(i);
        if(vv[xx[i]].size() > 1) candidates.push_back(xx[i]);
    }
    if(foo[0]) {
        cout << "AND " << 1 << " " << foo[0] << endl;
        int tmp; cin >> tmp;
        ans[1] = tmp;
    }
    else if(!candidates.empty()) {
        int fir = vv[candidates[0]][0];
        int sec = vv[candidates[0]][1];
        cout << "AND " << fir << " " << sec << endl;
        int tmp; cin >> tmp;

        for(int j = 0; j <= mxbit; j++) {
            int chk = xx[fir] & (1 << j);

            /// same and 0 or, different and 1
            if((chk == 0 && (tmp & (1 << j)) == 0) || (chk && (tmp & (1 << j)))) {
                /// set 0
                ans[1] = ans[1] & (~(1 << j));
            }
            else {
                /// set 1
                ans[1] = ans[1] | (1 << j);
            }
        }
    }
    else if(foo[1]) {
        /// 2
        cout << "AND " << 1 << " " << foo[1] << endl;
        int tmp; cin >> tmp;
        ans[1] = tmp;

        cout << "AND " << 1 << " " << same_first_bit << endl;
        cin >> tmp;
        if((tmp & (1 << 0)) == 0) {
            /// set first bit as 0
            ans[1] = ans[1] & (~(1 << 0));
        }
        else {
            /// set first bit as 1
            ans[1] = ans[1] | (1 << 0);
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= mxbit; j++) {
            int chk = (xx[i] & (1 << j));

            // same and 0 or different and 1
            if((!chk && (ans[1] & (1 << j)) == 0) || (chk && (ans[1] & (1 << j)))) {
                /// set 0
                ans[i] = ans[i] & (~(1 << j));
            }
            else {
                /// set  1
                ans[i] = ans[i] | (1 << j);
            }
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
/**
*/
