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
vector<int> freq[30];

int cost(int le, int ri, int cc) {
    // for(int i = le - 1; i < ri; i++) {
    //     if(str[i] != (cc + 'a')) {
            
    //     }
    // }
    int p2 = upper_bound(freq[cc].begin(), freq[cc].end(), ri) - freq[cc].begin();
    int p1 = lower_bound(freq[cc].begin(), freq[cc].end(), le) - freq[cc].begin();
    return ri - le + 1 - (p2 - p1);
}

int func(int le, int ri, int cc) {
    int ans = INT_MAX;
    if(cc >= 26) return ans;
    
    if(le == ri) {
        return cost(le, ri, cc);
    }
    int mid = (le + ri) / 2;

    ///setting right side as cc
    ans = min(ans, func(le, mid, cc + 1) + cost(mid + 1, ri, cc));
    /// setting left side as cc
    ans = min(ans, cost(le, mid, cc) + func(mid + 1, ri, cc + 1));
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        for(int i = 0; i < 26; i++) {
            freq[i].clear();
        }
        cin >> n;
        cin >> str;
        for(int i = 0; i < str.size(); i++) {
            freq[str[i] - 'a'].push_back(i + 1);
        }
        cout << func(1, n, 0) << endl;
    }
    return 0;
}
/**
*/
