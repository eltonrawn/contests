#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int freq[26];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str, nstr;
    cin >> str;
    nstr = str;
    for(int i = 0; i < str.size(); i++) {
        freq[str[i] - 'A']++;
    }
    int odd = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2)
            odd++;
    }
    if(odd > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int le = 0, ri = str.size() - 1;
    for(int i = 0; i < 26; i++) {
        while(freq[i] > 1) {
            nstr[le++] = i + 'A';
            nstr[ri--] = i + 'A';
            freq[i] -= 2;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i]) {
            nstr[le++] = i + 'A';
            freq[i] -= 1;
        }
    }
    cout << nstr << endl;

    return 0;
}
/**
*/
