#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[SZ];
set<int> st[SZ];
int pos[SZ];
int ans;

void insert_into(int l, int val) {
    auto it = st[l].upper_bound(val);
    
    if(it != st[l].end()) {
        if(val + 1 != (*it)) ans++;
    }
    else if(val != n) {
        ans++;
    }
    
    if(it != st[l].begin()) {
        it--;
        if((*it + 1) == val) ans--;
    }

    st[l].insert(val);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        st[ara[i]].insert(i);
    }

    for(int i = 1; i <= m; i++) {
        pos[i] = i;
        int past = -1;
        for(int val: st[i]) {
            if(past == -1) {
                past = val;
                continue;
            }
            if(past + 1 != val) ans++;
            past = val;
        }
        
        if(past != n) ans++;
    }
    cout << ans << endl;

    for(int i = 1; i < m; i++) {
        int origl, origr;
        cin >> origl >> origr;
        int l = pos[origl];
        int r = pos[origr];
        if(st[l].size() < st[r].size()) {
            swap(l, r);
        }
        int past = -1;
        for(int val: st[r]) {
            if(past == -1) {
                past = val;
                continue;
            }
            if(past + 1 != val) ans--;
            insert_into(l, past);
            past = val;
        }
        if(past != n) ans--;
        insert_into(l, past);

        pos[origl] = l;
        pos[origr] = l;
        cout << ans << endl;
    }

    return 0;
}
/**
*/
