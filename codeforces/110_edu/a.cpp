#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<int> ara, vv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        ara.clear();
        vv.clear();
        for(int i = 0; i < 4; i++) {
            int tmp; cin >> tmp;
            ara.push_back(tmp);
            vv.push_back(tmp);
        }
        sort(vv.begin(), vv.end(), greater<int>());
        if((ara[0] == vv[0] || ara[0] == vv[1]) && (ara[1] == vv[0] || ara[1] == vv[1])) {
            cout << "NO" << endl;
            continue;
        }
        if((ara[2] == vv[0] || ara[2] == vv[1]) && (ara[3] == vv[0] || ara[3] == vv[1])) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
/**
*/
