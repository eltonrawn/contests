#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int func(int pos, vector<int> &vec) {
    // cout << "pos " << pos << endl;
    if(pos < 0) {
        return vec.size();
    }
    vector<int> zz, oo;

    for(int vv: vec) {
        if(vv & (1 << pos)) {
            oo.PB(vv);
        }
        else {
            zz.PB(vv);
        }
    }
    int ans = 0;
    /// work with zero
    if(zz.size()) {
        int cc = 0;
        if(oo.size() >= 1) {
            cc = 1;
        }
        int tmp = func(pos - 1, zz);
        ans = max(ans, cc + tmp);
        // cout << pos << " " << 0 << " : " << tmp << "\n";
    }
    
    /// work with one
    if(oo.size()) {
        int cc = 0;
        if(zz.size() >= 1) {
            cc = 1;
        }
        int tmp = func(pos - 1, oo);
        ans = max(ans, cc + tmp);
        // cout << pos << " " << 1 << " : " << tmp << "\n";
    }
    return ans;
}

int n;
vector<int> ara;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);tt
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    ara.resize(n);
    FOR(i, 0, n - 1) {
        cin >> ara[i];
    }

    // cout << func(30, ara) << " ";
    cout << n - func(30, ara) << endl;
    return 0;
}
/**
*/
