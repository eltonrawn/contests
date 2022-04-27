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

pair<LL, string> func(int pos) {
    
    if(pos * 2 + 1 >= str.size()) {
        // child
        string foo = ""; foo += str[pos];
        return {1, foo};
    }
    // not child
    pair<LL, string> a = func(pos * 2 + 1);
    pair<LL, string> b = func(pos * 2 + 2);
    if(a.second == b.second)
        return {(a.first * b.first) % MOD, str[pos] + a.second + b.second};
    else if(a.second < b.second)
        return {(a.first * b.first * 2LL) % MOD, str[pos] + a.second + b.second};
    else
        return {(a.first * b.first * 2LL) % MOD, str[pos] + b.second + a.second};
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> str;
    cout << func(0).first << endl;
    return 0;
}
/**
4
BAAAAAAAABBABAB
*/
