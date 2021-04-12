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

struct Data {
    LL a, b;
};

class cmp1 {
public:
    bool operator()(Data a, Data b) {
        LL amn = min(a.a, a.b);
        LL bmn = min(b.a, b.b);

        LL amx = max(a.a, a.b);
        LL bmx = max(b.a, b.b);

        if(amn == bmn) {
            return amx < bmx;
        }
        return amn < bmn;
    }
};

int n;
LL a[MX], b[MX];
vector<Data> vv;
set<LL> aout, bout;


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    FOR(i, 1, n) {
        cin >> b[i];
    }
    LL ans = 0;
    LL res = 0;

    FOR(i, 1, n) {
        vv.PB({a[i], b[i]});
        ans += abs(a[i] - b[i]);
    }
    res = ans;
    // cout << "res : " << res << endl;

    sort(vv.begin(), vv.end(), cmp1());

    for(Data data: vv) {
        // cout << data.a << " " << data.b << endl;
        if(data.b <= data.a) {
            if(aout.size())
                res = min(res, ans - (2LL * (min((*aout.rbegin()), data.a) - data.b)));
            bout.insert(data.a);
        }
        else {
            if(bout.size())
                res = min(res, ans - (2LL * (min((*bout.rbegin()), data.b) - data.a)));
            // cout << "hi2 " << min((*bout.rbegin()), data.b) << " " << data.a << "endl";
            aout.insert(data.b);
        }
    }
    cout << res << endl;
    return 0;
}
/**
*/
