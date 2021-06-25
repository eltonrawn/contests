#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL fact(int n) {
    LL ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int freq[26];

string str;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;
    }
    LL ans = fact(str.size());
    for(int i = 0; i < 25; i++) {
        if(freq[i])
            ans /= fact(freq[i]);
    }
    cout << ans << endl;
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while(next_permutation(str.begin(), str.end()));
    return 0;
}
/**
*/
