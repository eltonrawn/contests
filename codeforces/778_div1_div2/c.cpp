#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];
multiset<LL> st1, st2;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        st1.clear(); st2.clear();
        cin >> n;
        LL sum = 0;
        for(int i = 0; i < n; i++) {cin >> ara[i]; st1.insert(ara[i]); sum += ara[i];}
        st2.insert(sum);
        while(!st1.empty() && !st2.empty()) {
            if(*(--st2.end()) == *(--st1.end())) {
                st2.erase(--st2.end());
                st1.erase(--st1.end());
            }
            else if(*(--st2.end()) > *(--st1.end())) {
                LL val = *(--st2.end());
                st2.erase(--st2.end());
                LL a = val / 2;
                LL b = val - a;
                st2.insert(a); st2.insert(b);
            }
            else break;
        }
        if(st1.empty() && st2.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/**
*/
