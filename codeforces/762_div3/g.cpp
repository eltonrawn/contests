#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
int n, k;
PII ara[SZ];
int cost[SZ];
set<PII> row, col;
queue<PII> q;
set<PII> rem_yo;
map<PII, int> mp;
multiset<int> fn_st;

int handle(set<PII> &myset, set<PII> &otherset, bool shoja, PII top) {
    int mntm = INT_MAX;
    if(myset.empty()) return mntm;
    auto it1 = myset.lower_bound(top);
    while(it1 != myset.end()) {
        PII yoyo = *it1;
        if(yoyo.first != top.first) break;
        if(yoyo.second - top.second <= k) rem_yo.insert(*it1);
        else break;
        it1++;
    }
    auto it2 = myset.lower_bound(top);
    while(true) {
        if(it2 == myset.begin()) break;
        it2--;
        PII yoyo = *it2;
        if(yoyo.first != top.first) break;
        if(top.second - yoyo.second <= k) rem_yo.insert(*it2);
        else break;
    }
    
    
    while(!rem_yo.empty()) {
        PII yo = *rem_yo.begin();
        rem_yo.erase(yo);
        myset.erase(yo);
        otherset.erase({yo.second, yo.first});
        if(shoja) {
            q.push(yo);
        }
        else {
            q.push({yo.second, yo.first});
        }
        
        PII yoyo = q.back();
        mntm = min(mntm, cost[mp[yoyo]]);
    }
    return mntm;
}
 
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        row.clear();
        col.clear();
        mp.clear();
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i].first >> ara[i].second;
            cin >> cost[i];
            row.insert(ara[i]);
            col.insert({ara[i].second, ara[i].first});
            mp[ara[i]] = i;
        }

        fn_st.clear();
        for(int i = 1; i <= n; i++) {
            if(row.find(ara[i]) == row.end()) {
                continue;
            }
 
            q.push(ara[i]);
            row.erase(ara[i]);
            col.erase({ara[i].second, ara[i].first});
            int mntm = cost[i];
            while(!q.empty()) {
                PII top = q.front();
                q.pop();
        
                // mntm = min(mntm, handle_row(top));
                // mntm = min(mntm, handle_col(top));

                mntm = min(mntm, handle(row, col, 1, top));
                mntm = min(mntm, handle(col, row, 0, {top.second, top.first}));
            }
            fn_st.insert(mntm);
        }
 
        int ans = -1;
        for(int i = 0; i < n && !fn_st.empty(); i++) {
            ans = i;
            while(!fn_st.empty()) {
                auto it = fn_st.begin();
                if(*it > i) break;
                fn_st.erase(it);
            }
            if(fn_st.empty()) break;
            auto it = fn_st.end(); it--;
            fn_st.erase(it);
        }
 
        cout << ans << endl;
    }
    return 0;
}
/**
start: 11:40 pm
idea: 11:52 pm

comment: solved one day later because couldn't find the bug. 
Turned out, I was using queue as a stack. stupidest mistake one can make. disappointed.
*/