#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<int> ara;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        ara.clear();
        for(int i = 1; i <= 3; i++) {
            int tmp; cin >> tmp;
            ara.push_back(tmp);
        }
        sort(ara.begin(), ara.end());
        if(ara[1] != ara[2]) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ara[0] << " " << ara[0] << " " << ara[2] << endl;
    }
    return 0;
}
/**
*/
