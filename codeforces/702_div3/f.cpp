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
map<int, int> cnt;
vector<PII> vv;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cnt.clear(); vv.clear();
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            cnt[ara[i]]++;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            vv.push_back({it->second, it->first});
        }
        LL ans = n;
        LL prev_can = 0;
        LL prev_deleted = 0;
        LL total_taken = 0;
        sort(vv.begin(), vv.end(), greater<PII>());
        LL curr_freq = -1;
        for(int i = 0; i < vv.size(); i++) {
            if(curr_freq == -1)
                curr_freq = vv[i].first;
            
            while(curr_freq > vv[i].first) {
                prev_deleted += prev_can;
                ans = min(ans, prev_deleted + (n - total_taken));
                curr_freq--;
            }

            int j = i;
            LL freq = 0;
            while(j < vv.size() && vv[j].first == vv[i].first) {
                total_taken += vv[j].first;
                j++;
            }
            j--;
            prev_deleted += prev_can;
            ans = min(ans, prev_deleted + (n - total_taken));
            curr_freq--;
            // cout << prev_deleted << " " << total_taken << " " << prev_deleted + (n - total_taken) << " ";
            prev_can += j - i + 1;
            // cout << prev_can << endl;
            i = j;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
