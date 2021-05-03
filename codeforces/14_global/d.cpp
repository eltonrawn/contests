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
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int n, l, r;
// int ara[SZ];
// vector<int> lvec, rvec;
map<int, int> lmp, rmp;
set<PII, cmp1> lst, rst;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> l >> r;
        // lvec.clear();rvec.clear();
        lmp.clear();rmp.clear();
        lst.clear(); rst.clear();
        LL ans = 0;

        int lcnt = 0;
        int rcnt = 0;

        for(int i = 1; i <= l; i++) {
            int tmp;cin >> tmp;
            // lvec.push_back(tmp);
            lmp[tmp]++;
            lcnt++;
        }
        for(int i = 1; i <= r; i++) {
            int tmp;cin >> tmp;
            if(lmp[tmp]) {
                lmp[tmp]--;
                lcnt--;
                continue;
            }
            // rvec.push_back(tmp);
            rmp[tmp]++;
            rcnt++;
        }

        // if(lvec.size() > rvec.size()) {
        //     swap(lvec, rvec);   
        //     swap(lmp, rmp);
        // }

        for(auto it = lmp.begin(); it != lmp.end(); it++) {
            lst.insert({it->second, it->first});
        }

        for(auto it = rmp.begin(); it != rmp.end(); it++) {
            rst.insert({it->second, it->first});
        }

        while(lcnt != rcnt) {
            if(lcnt > rcnt) {
                if((*lst.begin()).first < 2) {
                    break;
                }
                PII pr = *lst.begin();lst.erase(lst.begin());
                pr.first -= 2;
                lst.insert(pr);
                lcnt -= 2;
                ans++;
            }
            else if(rcnt > lcnt) {
                if((*rst.begin()).first < 2) {
                    break;
                }
                PII pr = *rst.begin();rst.erase(rst.begin());
                pr.first -= 2;
                rst.insert(pr);
                rcnt -= 2;
                ans++;
            }
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
