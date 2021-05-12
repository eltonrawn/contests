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
vector< pair< pair<int, int>, int > > ans;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        LL sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            sum += ara[i];
        }
        if(sum % n) {
            cout << -1 << endl;
            continue;
        }
        ans.clear();
        LL indiv = sum / n;
        for(int i = 2; i <= n; i++) {
            if(ara[i] % i == 0) {
                // cout << i << " " << 1 << " " << ara[i] << endl;
                ans.push_back({{i, 1}, ara[i] / i});
                ara[1] += ara[i];
                ara[i] = 0;
                continue;
            }
            ans.push_back({{1, i}, i - (ara[i] % i)});
            ara[1] -= i - (ara[i] % i);
            ara[i] += i - (ara[i] % i);
            ans.push_back({{i, 1}, ara[i] / i});

            ara[1] += ara[i];
            ara[i] = 0;
        }

        // for(int i = 1; i <= n; i++) {
        //     cout << ara[i] << " ";
        // }
        // cout << endl;

        for(int i = 2; i <= n; i++) {
            ans.push_back({{1, i}, indiv});
            ara[1] -= indiv;
            ara[i] += indiv;
        }
        cout << ans.size() << endl;
        for(pair< pair< int, int >, int > val: ans) {
            cout << val.first.first << " " << val.first.second << " " << val.second << endl;
        }

        // for(int i = 1; i <= n; i++) {
        //     cout << ara[i] << " ";
        // }
        // cout << endl;
    }
    return 0;
}
/**
*/
