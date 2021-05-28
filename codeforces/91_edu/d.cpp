#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
LL x, k, y;
int a[SZ], b[SZ];
vector<int> pos;
LL inf = 100000000000000000LL;

LL ans = 0;
bool chk = 1;

void ff(int le, int ri) {
    if(le >= ri - 1) return;
    
    int pastmx = max(a[le], a[ri]);
    int mx = 0;
    for(int i = le + 1; i < ri; i++) {
        mx = max(mx, a[i]);
    }
    LL ret = inf;
    int start = 0;
    if(pastmx < mx) {
        /// have to take atleast one x
        start = 1;
    }
    for(int i = start; (i * k) <= (ri - le - 1); i++) {
        ret = min(ret, (x * i) + (ri - le - 1 - (i * k)) * y);
    }
    if(ret == inf) chk = 0;
    ans += ret;
    // cout << le << " " << ri << " : " << ret << endl;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pos.clear();
    cin >> n >> m;
    cin >> x >> k >> y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int p1, p2;
    for(p1 = 1, p2 = 1; p1 <= n && p2 <= m; p1++) {
        if(a[p1] == b[p2]) {
            pos.push_back(p1);
            p2++;
        }
    }
    if(pos.size() != m) {
        cout << -1 << endl;
        return 0;
    }
    LL tmp;
    for(int i = 0; i < pos.size() - 1; i++) {
        ff(pos[i], pos[i + 1]);
    }
    /// handle left
    ff(0, pos[0]);
    
    /// handle right
    ff(pos.back(), n + 1);

    if(!chk) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}
/**
*/
