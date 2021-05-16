#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int x[SZ];
char dir[SZ];
PII pr[SZ];
map<int, int> ans;

void solve_for_parity(bool is_odd) {
    deque<PII> q;
    
    for(int i = 1; i <= n; i++) {
        if(is_odd && (pr[i].first % 2) == 0) {
            /// work with only odd
            continue;
        }

        if(!is_odd && (pr[i].first % 2)) {
            /// work with only even
            continue;
        }

        if(!q.empty() && q.back().second == 1 && pr[i].second == 0) {
            /// make pair
            int mid = (q.back().first + pr[i].first) / 2;
            ans[q.back().first] = mid - q.back().first;
            ans[pr[i].first] = pr[i].first - mid;

            q.pop_back();
            continue;
        }
        q.push_back(pr[i]);
    }
    while(!q.empty()) {
        if(q.front().second != 0) {
            break;
        }
        PII fir = q.front();
        q.pop_front();
        
        if(q.empty() || q.front().second != 0) {
            q.push_front(fir);
            break;
        }
        PII sec = q.front();
        q.pop_front();

        /// make pair
        int cc = fir.first - 0;
        int x = fir.first - cc;
        int y = sec.first - cc;

        int mid = (x + y) / 2;
        ans[fir.first] = mid - x + cc;
        ans[sec.first] = y - mid + cc;
    }

    while(!q.empty()) {
        if(q.back().second != 1) {
            break;
        }
        PII fir = q.back();
        q.pop_back();
        
        if(q.empty() || q.back().second != 1) {
            q.push_back(fir);
            break;
        }
        
        PII sec = q.back();
        q.pop_back();

        /// make pair
        int cc = m - sec.first;
        int x = fir.first + cc;
        int y = sec.first + cc;

        int mid = (x + y) / 2;
        ans[fir.first] = mid - x + cc;
        ans[sec.first] = y - mid + cc;
    }
    if(q.size() == 2) {
        /// 0, 1 or L, R available
        /// make pair
        PII fir = q.front();
        PII sec = q.back();

        int cc = min(fir.first - 0, m - sec.first);

        int x = fir.first - cc;
        int y = sec.first + cc;

        if(x == 0 && y != m) {
            int tmp = m - y;
            x += tmp;
            y += tmp;
            cc += tmp;
        }
        else if(x != 0 && y == m) {
            int tmp = x - 0;
            x -= tmp;
            y -= tmp;
            cc += tmp;
        }

        int mid = (x + y) / 2;
        ans[fir.first] = mid - x + cc;
        ans[sec.first] = y - mid + cc;
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        ans.clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
            pr[i].first = x[i];
            ans[x[i]] = -1;
        }
        for(int i = 1; i <= n; i++) {
            cin >> dir[i];
            pr[i].second = (dir[i] == 'L') ? 0 : 1;
        }
        
        sort(pr + 1, pr + n + 1);
        
        solve_for_parity(0);
        solve_for_parity(1);

        for(int i = 1; i <= n; i++) {
            cout << ans[x[i]] << " ";
        }
        cout << endl;

    }
    return 0;
}
/**
*/
