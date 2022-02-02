#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 500010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string s;
map<PII, int> pos;
vector<int> vv[SZ];
int ans[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        cin >> s;
        pos.clear();
        for(int i = 1; i <= s.size(); i++) {
            vv[i].clear();
        }
        
        int cnt1 = 0;
        int cnt2 = 0;
        int cc = 1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'D')
                cnt1++;
            else
                cnt2++;
            
            PII pr = {cnt1 / __gcd(cnt1, cnt2), cnt2 / __gcd(cnt1, cnt2)};

            if(pos[pr] == 0) {
                pos[pr] = cc++;
                ans[i] = 1;
            }
            else {
                ans[i] = 1 + ans[vv[pos[pr]].back()];
            }
            
            vv[pos[pr]].push_back(i);
        }
        for(int i = 0; i < s.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
*/
