#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int n;
int ara[SZ];
vector<PII> vv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        int mn = INT_MAX;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            mn = min(mn, ara[i]);
        }
        int mnpos;
        for(int i = 1; i <= n; i++) {
            if(ara[i] == mn) {
                mnpos = i;
                break;
            }
        }

        vv.clear();
        
        LL past = mn;
        int pos = mnpos + 1;
        for(LL i = mn; pos <= n; i++) {
            if(__gcd(past, i) == 1) {
                vv.push_back({pos, i});
                pos++;
                past = i;
            }
        }

        past = mn;
        pos = mnpos - 1;
        for(LL i = mn; pos >= 1; i++) {
            if(__gcd(past, i) == 1) {
                vv.push_back({pos, i});
                pos--;
                past = i;
            }
        }

        cout << vv.size() << endl;
        for(PII val: vv) {
            cout << val.first << " " << mnpos << " " << val.second << " " << ara[mnpos] << endl;
        }
    }
    return 0;
}
/**
*/
