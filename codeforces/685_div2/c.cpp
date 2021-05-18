#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
string a, b;

int src[30], tar[30];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> k;
        cin >> a >> b;
        memset(src, 0, sizeof(src));
        memset(tar, 0, sizeof(tar));
        for(char ch: a)
            src[ch - 'a']++;
        for(char ch: b)
            tar[ch - 'a']++;
        
        bool chk = 1;
        for(int i = 0; i <= 25; i++) {
            if(tar[i] > src[i]) {
                chk = 0;break;
            }
            src[i] -= tar[i];
            if(src[i] % k) {
                chk = 0;break;
            }
            src[i + 1] += src[i];
        }
        cout << (chk == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}
/**
*/
