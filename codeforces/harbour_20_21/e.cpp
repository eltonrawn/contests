#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[SZ];
int sfreq[SZ]; 
// int shift[SZ];
bool vis[SZ];
int nara[SZ];

bool solve(int shifted) {
    for(int i = 0; i < n; i++) {
        vis[i] = 0;
        nara[i] = ara[(i + shifted) % n];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int u = i;
        int v = nara[u];
        int cnt = 0;
        while(!vis[u]) {
            vis[u] = 1;
            cnt++;
            u = v;
            v = nara[u];
        }
        ans += cnt - 1;
    }
    return ans <= m;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            sfreq[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            cin >> ara[i];
            ara[i]--;

            int shifted = ara[i] % n;
            if(i >= ara[i])
                shifted = i - ara[i];
            else
                shifted = n - ara[i] + i;
            sfreq[shifted]++;
            // shift[i] = shifted;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(sfreq[i] >= (n / 3)) {
                if(solve(i))
                    ans.push_back(i);
            }
        }
        cout << ans.size() << " ";
        for(int val: ans)
            cout << val << " ";
        cout << endl;
        
    }
    return 0;
}
/**
 * 1 2 3 4 5 6
 * 2 5 1 3 4 6
 *       1 1
 * 
 * 1 2 3 4 5 6
 * 4 5 6 1 2 3 
*/
