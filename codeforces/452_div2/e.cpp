#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class Cmp {
public:
    bool operator()(PII a, PII b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

int n;
int ara[SZ];
set<PII, Cmp> st;
set<int> segs;
int cnt[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i <= n; i++) {
        int j = i;
        while(j <= n && ara[j] == ara[i]) {
            j++;
        }
        j--;
        cnt[i] = j - i + 1;
        st.insert({i, cnt[i]});
        segs.insert(i);
        i = j;
    }
    int ans = 0;
    while(!st.empty()) {
        PII top = *st.begin();
        st.erase(st.begin());
        ans++;
        auto it = segs.find(top.first);
        if(it != segs.begin()) {
            it++;
            if(it != segs.end()) {
                /// get the one after
                int riidx = *it;
                it--; it--;
                /// get the one before
                int leidx = *it;
                if(ara[riidx] == ara[leidx]) {
                    it++; it++;
                    segs.erase(it);
                    
                    st.erase({leidx, cnt[leidx]});
                    st.erase({riidx, cnt[riidx]});
                    cnt[leidx] += cnt[riidx];
                    st.insert({leidx, cnt[leidx]});
                }
            }
        }

        segs.erase(top.first);

    }
    cout << ans << endl;

    return 0;
}
/**
start: 12:42 am
end: 1:02 am
duration: 20 mins
comment: this should've been done under 15 mins. immediately got the solution.
*/
