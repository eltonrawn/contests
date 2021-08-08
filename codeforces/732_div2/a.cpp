#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> pos, neg;
int a[SZ], b[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        pos.clear(); neg.clear();
        for(int i = 1; i <= n; i++) {
            if(a[i] > b[i]) {
                for(int j = 1; j <= (a[i] - b[i]); j++)
                    neg.push_back(i);
            }
            else if(a[i] < b[i]) {
                for(int j = 1; j <= (b[i] - a[i]); j++)
                    pos.push_back(i);
            }
        }
        if(pos.size() != neg.size()) {
            cout << -1 << endl;
            continue;
        }
        cout << neg.size() << endl;
        for(int i = 0; i < neg.size(); i++) {
            cout << neg[i] << " " << pos[i] << endl;
        }
    }
    return 0;
}
/**
*/
