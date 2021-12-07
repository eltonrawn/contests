#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
int n;
pair<LL, LL> ara[SZ];
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    LL tmp = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i].first >> ara[i].second;
        if(ara[i].first > ara[i].second) {
            swap(ara[i].first, ara[i].second);
        }
        tmp = max(tmp, ara[i].second * ara[i].first);
    }

    sort(ara + 1, ara + n + 1);
    LL ans = 0;
    LL hi = ara[n].second;
    for(int i = n - 1; i >= 1; i--) {
        ans = max(ans, ara[i].first * min(hi, ara[i].second));
        hi = max(hi, ara[i].second);
    }

    if(tmp % 2 == 0) {
        cout << max(ans, tmp / 2) << "." << 0 << endl;
    }
    else {
        if(ans > tmp / 2) {
            cout << ans << "." << 0 << endl;
        }
        else {
            cout << tmp / 2 << "." << 5 << endl;
        }
    }
    // for(int i = 1; i < n; i++) {
    //     ans = max(ans, min(ara[i].first, ara[i + 1].first) * min(ara[i].second, ara[i + 1].second));
    // }
    // cout << fixed << setprecision(1) << ans << endl;
 
    return 0;
}
/**
start: 
*/