#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int a[SZ], b[SZ];

bool chk(int taken) {
    // cout << "taken : " << taken << endl;
    int ri = taken - 1;
    int le = 0;
    for(int i = 1; i <= n && ri >= 0; i++) {
        // cout << a[i] << " " << b[i] << " ";
        if(a[i] >= ri && b[i] >= le) {
            // cout << "taken";
            ri--;
            le++;
        }
        // cout << endl;
    }
    if(ri < 0) {
        return true;
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            // cout << mid << " : " << chk(mid) << endl;
            if(chk(mid)) {
                lo = mid;
            }
            else {
                hi = mid - 1;
            }
        }
        // cout << "ans ";
        cout << lo << endl;
    }
    return 0;
}
/**
*/
