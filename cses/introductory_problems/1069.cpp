#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        int j;
        int cnt = 0;
        for(j = i ; j < str.size() && str[i] == str[j]; j++) {
            cnt++;
        }
        ans = max(ans, cnt);
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}
/**
*/
