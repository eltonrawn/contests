#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL s, make;
vector<int> adjl[SZ], coin[SZ];
vector<LL> cost[SZ];

/// {difference to substract, w, no_of_leave}
/// {difference -> (w * no_of_leave) - (w / 2 * no_of_leave)}
multiset< pair<LL, pair<LL, int> > > ms1, ms2;

int func(int u, int par) {
    int tot_leave = 0;
    for(int i = 0; i < adjl[u].size(); i++) {
        int v = adjl[u][i];
        LL w = cost[u][i];
        if(v == par) continue;
        int no_of_leave = func(v, u);
        tot_leave += no_of_leave;
        LL half_w = w / 2;
        if(coin[u][i] == 1)
            ms1.insert({(w * no_of_leave) - (half_w * no_of_leave), {w, no_of_leave}});
        if(coin[u][i] == 2)
            ms2.insert({(w * no_of_leave) - (half_w * no_of_leave), {w, no_of_leave}});
        make += (w * no_of_leave);
    }
    return (tot_leave == 0) ? 1 : tot_leave;
}

void do_operation(multiset< pair<LL, pair<LL, int> > > &ms) {
    auto it = ms.end(); it--;
    pair<LL, pair<LL, int> > top = *it;
    ms.erase(it);
    make -= top.first;
    top.second.first = top.second.first / 2;
    LL half_w = top.second.first / 2;
    top.first = (top.second.first * top.second.second) - (half_w * top.second.second);
    ms.insert(top);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> s;
        for(int i = 1; i <= n; i++) {
            adjl[i].clear(); cost[i].clear(); coin[i].clear();
        }
        ms1.clear(); ms2.clear(); make = 0;
        for(int i = 1; i < n; i++) {
            int u, v, cc; LL w;
            cin >> u >> v >> w >> cc;
            
            adjl[u].push_back(v);
            cost[u].push_back(w);
            coin[u].push_back(cc);

            
            adjl[v].push_back(u);
            cost[v].push_back(w);
            coin[v].push_back(cc);
        }
        func(1, 0);
        int ans = 0;
        while(make > s) {
            if(ms2.empty()) {
                do_operation(ms1);
                ans++;
                continue;
            }
            if(ms1.empty()) {
                do_operation(ms2);
                ans += 2;
                continue;
            }

            auto it1 = ms1.end(); it1--;
            pair<LL, pair<LL, int> > top1 = *it1;
            ms1.erase(it1);

            if(make - top1.first <= s) {
                ans++;
                break;
            }

            vector<LL> tmp;
            tmp.push_back(top1.first);

            LL yo = top1.second.first / 2;
            LL half_yo = yo / 2;
            tmp.push_back((yo * top1.second.second) - (half_yo * top1.second.second));
            if(!ms1.empty()) {
                it1 = ms1.end(); it1--;
                tmp.push_back((*it1).first);
            }
            sort(tmp.begin(), tmp.end(), greater<LL>());
            ms1.insert(top1);

            auto it2 = ms2.end(); it2--;
            pair<LL, pair<LL, int> > top2 = *it2;
            // ms_2.erase(it2);

            if(tmp[0] + tmp[1] <= top2.first) {
                do_operation(ms2);
                ans += 2;
                continue;
            }
            do_operation(ms1);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
 * c1_set -> set
 * c2_set -> set
 * 
 * if(make - c1_set.back() <= s) take this c1 and end
 * 
 * /// otherwise we will take 2
 * if(c1_set.back() + c1_set.2nd_back() <= c2_set.back()) -> take c2 and continue
 * 
 * if(c1_set.back() + c1_set.2nd_back() > c2_set.back()) -> take c1_set.back() and continue
 * 
 * cases ->
 * make - c1_set.back() - c2_set.back() <= s
 * 
 * 
*/
