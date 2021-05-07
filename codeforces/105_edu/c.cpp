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
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<int> aa, bb;

LL func() {
    LL ans = 0;
    int apos = aa.size() - 1;
    LL cc = 0;
    while(!bb.empty() && apos >= 0) {
        // cout << bb.back() << " " << aa[apos] << endl;
        // cout << "shusu : " << aa[apos] << " " << bb.back() << endl;
        
        if(bb.back() < aa[apos]) {
            apos--;
            continue;
        }
        
        
        int target = bb.back() - apos;
        int pos = lower_bound(bb.begin(), bb.end(), target) - bb.begin();
        ans = max(ans, (LL)bb.size() - pos + cc);


        if(bb.back() == aa[apos]) {
            apos--;
            cc++;
        }
        bb.pop_back();
    }
    // cout << "yyo : " << ans << endl;
    return ans;
}

int n, m;
int a[MX], b[MX];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        FOR(i, 0, n - 1) {
            cin >> a[i];
        }
        FOR(i, 0, m - 1) {
            cin >> b[i];
        }

        aa.clear();bb.clear();
        FOR(i, 0, n - 1) {
            if(a[i] > 0) {
                aa.PB(a[i]);
            }
        }
        FOR(i, 0, m - 1) {
            if(b[i] > 0) {
                bb.PB(b[i]);
            }
        }

        LL ans = func();

        aa.clear();bb.clear();
        ROF(i, n - 1, 0) {
            if(a[i] < 0) {
                aa.PB(-1 * a[i]);
            }
        }
        ROF(i, m - 1, 0) {
            if(b[i] < 0) {
                bb.PB(-1 * b[i]);
            }
        }
        ans += func();
        cout << ans << endl;

    }
    return 0;
}
/**
*/
