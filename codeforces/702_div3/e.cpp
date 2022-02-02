#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];
map<int, int> cnt, idx;
vector<PII> vv;
vector<int> ans;
vector<int> pos[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cnt.clear(); idx.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)
            pos[i].clear();

        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            cnt[ara[i]]++;
        }

        vv.clear(); ans.clear();
        int cc = 1;
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            LL val = it->first;
            LL freq = it->second;
            vv.push_back({val, freq});
            idx[val] = cc;
            cc++;
        }

        for(int i = 1; i <= n; i++) {
            pos[ idx[ara[i]] ].push_back(i);
        }

        int prev_freq = 0;
        LL prev = 0;
        for(int i = 0; i < vv.size() - 1; i++) {
            LL val = vv[i].first;
            LL freq = vv[i].second;
            prev += val * freq;
            if(prev >= vv[i + 1].first) {
                for(int j = 0; j < freq; j++) {
                    ans.push_back(pos[idx[val]][j]);
                }
            }
            else {
                ans.clear();
            }
        }
        for(int j = 0; j < vv.back().second; j++) {
            ans.push_back(pos[ idx[vv.back().first] ][j]);
        }


        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(int val: ans)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
/**
*/
