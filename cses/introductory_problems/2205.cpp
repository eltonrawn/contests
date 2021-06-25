#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<LL> ans;
    ans.push_back(0);
    LL base = 1;
    for(int i = 1; i <= n; i++) {
        int last = ans.size() - 1;
        for(int j = last; j >= 0; j--) {
            ans.push_back(base + ans[j]);
        }
        base *= 2;
    }
    for(LL val: ans) {
        for(int i = n - 1; i >= 0; i--) {
            cout << (val & (1 << i) ? 1 : 0);
        }
        // cout << " " << val;
        cout << endl;
    }
    return 0;
}
/**
 * 000000000 0
 * 
 * 000000001 1
 * 
 * 000000011 3
 * 000000010 2
 * 
 * 000000110 6
 * 000000111 7
 * 000000101 5
 * 000000100 4
 * 
 * 000001100 12
 * 000001101 13
 * 000001111 15
 * 000001110 14
 * 000001010 10
 * 000001011 11
 * 000001001 11
 * 000001000 8
 * 
 * 
 * 
*/
