#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
int freq[3];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        
        for(int i = 0; i < 3; i++)
            freq[i] = 0;
        
        for(int i = 1; i <= n; i++) {
            freq[ara[i] % 3]++;
        }

        int ans = 0;
        int limit = n / 3;
        while(true) {
            bool is_same = 1;
            for(int i = 0; i < 3; i++) {
                // cout << freq[i] << " ";
                if(freq[i] > limit) {
                    is_same = 0;
                    ans += freq[i] - limit;
                    freq[(i + 1) % 3] += freq[i] - limit;
                    freq[i] -= freq[i] - limit;
                }
            }
            if(is_same)
                break;
        }
        cout << ans << endl;

    }
    return 0;
}
/**
*/
