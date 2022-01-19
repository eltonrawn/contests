#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, q;
int ara[SZ], inc[SZ];
map<PII, int> mp;
LL ans = 0;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        ans += ara[i];
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int s, t, u;
        cin >> s >> t >> u;
        if(mp[{s, t}] != 0) {
            // remove it first
            int tmp = mp[{s, t}];
            inc[tmp]--;
            if(inc[tmp] < ara[tmp]) {
                ans++;
            }
        }
        mp[{s, t}] = 0;
        // add it
        if(u != 0) {
            mp[{s, t}] = u;
            inc[u] += 1;
            if(inc[u] <= ara[u]) {
                ans--;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
/**
start: 11 am
end: 12:10 am
comment: couldn't prove mathematically but proved with intuition. have to read editorial again

tags: repeat
*/
