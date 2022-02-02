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
vector<int> vv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> str;
        vv.clear();
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '*') {
                vv.push_back(i);
            }
        }
        if(vv.empty()) {
            cout << 0 << endl;
            continue;
        }
        int le, ri;
        if(vv.size() % 2) {
            int mid = vv[vv.size() / 2];
            le = mid - 1;
            ri = mid + 1;
        }
        else {
            le = (vv[(vv.size() - 1) / 2] + vv[(vv.size()) / 2]) / 2;
            ri = le + 1;
        }
        // cout << le << " " << ri << endl;
        LL ans = 0;
        for(int i = vv.size() - 1; i >= 0; i--) {
            if(vv[i] <= le) {
                ans += le - vv[i];
                le--;
            }
        }
        for(int i = 0; i < vv.size(); i++) {
            if(vv[i] >= ri) {
                ans += vv[i] - ri;
                ri++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
