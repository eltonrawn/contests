#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class cmp1 {
public:
    bool operator()(PII a, PII b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};

int n, l, r;
map<int, int> lmp, rmp;
set<PII, cmp1> rst;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> l >> r;
        // lvec.clear();rvec.clear();
        lmp.clear();rmp.clear();rst.clear();
        LL ans = 0;

        int lcnt = 0;
        int rcnt = 0;

        for(int i = 1; i <= l; i++) {
            int tmp;cin >> tmp;
            lmp[tmp]++;lcnt++;
        }
        for(int i = 1; i <= r; i++) {
            int tmp;cin >> tmp;
            if(lmp[tmp]) {
                lmp[tmp]--;lcnt--;
                continue;
            }
            rmp[tmp]++;rcnt++;
        }

        if(lcnt > rcnt) {
            swap(lmp, rmp);
            swap(lcnt, rcnt);
        }

        for(auto it = rmp.begin(); it != rmp.end(); it++)
            rst.insert({it->second, it->first});

        while(rcnt > lcnt) {
            if((*rst.begin()).first < 2)break;
            PII pr = *rst.begin();rst.erase(rst.begin());
            pr.first -= 2;
            rst.insert(pr);
            rcnt -= 2;
            ans++;
        }
        // cout << lcnt << " " << rcnt << endl;
        LL tot = lcnt + rcnt;
        ans += abs(tot / 2 - lcnt);
        ans += tot / 2;
        cout << ans << endl;
    }
    return 0;
}
/**
*/
