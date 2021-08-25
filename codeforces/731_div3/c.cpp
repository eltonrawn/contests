#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int k, n, m;
int a[SZ], b[SZ];
vector<int> ans;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> k >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        int p1 = 1, p2 = 1;
        ans.clear();
        while(true) {
            if(p1 <= n && (a[p1] == 0 || a[p1] <= k)) {
                ans.push_back(a[p1]);
                if(a[p1] == 0) k++;
                p1++; continue;
            }
            if(p2 <= m && (b[p2] == 0 || b[p2] <= k)) {
                ans.push_back(b[p2]);
                if(b[p2] == 0) k++;
                p2++; continue;
            }
            break;
        }
        if(ans.size() == n + m) {
            for(int val: ans)
                cout << val << " ";
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }

    }
    return 0;
}
/**
*/
