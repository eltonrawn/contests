#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++) {
        if(str[i] == '0') continue;
        if(i % 2 == 0) cout << "Takahashi";
        else cout << "Aoki";
        cout << endl;
        return 0;
    }
    return 0;
}
/**
*/
