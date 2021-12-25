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
int deg[SZ];
vector<int> adjl[SZ];

class Cmp {
public:
    bool operator()(PII a, PII b) {
        if(a.second == b.second) {
            if(ara[a.first] == ara[b.first]) {
                return a.first < b.first;
            }
            return ara[a.first] < ara[b.first];
        }
        return a.second < b.second;
    }
};

set<PII, Cmp> st;
set<int> c_st, m_st;

void rem_dep_st(int u) {
    for(int v: adjl[u]) {
        st.erase({v, deg[v]});
        deg[v]--;
        // cout << v << " " << deg[v] << endl;
        st.insert({v, deg[v]});
    }
}

void clear_m_st() {
    for(int u: m_st) {
        rem_dep_st(u);
    }
    m_st.clear();
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        adjl[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        st.insert({i, deg[i]});
    }

    // for(PII yoyo: st) {
    //     cout << "st : " << yoyo.first << " " << yoyo.second << endl;
    // }
    
    int ans = 0;
    while(!st.empty()) {
        PII top = *st.begin();
        // cout << top.first << " " << top.second << endl;
        // if(top.first == 3 && top.second == 1) break;
        int u = top.first;
        if(top.second) {
            /// clear out c_st and m_st
            // cout << "hi" << endl;
            if(!c_st.empty()) ans++;
            c_st.clear();
            clear_m_st();
            continue;
        }
        st.erase(st.begin());
        if(ara[u] == 0) {
            /// main processor
            if(c_st.empty()) {
                st.erase({u, deg[u]});
                rem_dep_st(u);
            }
            else {
                st.erase({u, deg[u]});
                m_st.insert(u);
            }
        }
        else {
            /// co-precossor;
            st.erase({u, deg[u]});
            rem_dep_st(u);
            c_st.insert(u);
        }
    }
    if(!c_st.empty()) {
        ans++;
    }
    cout << ans << endl;


    return 0;
}
/**
start: 6:10 pm
end: 7:23 pm
duration: 1 hr 13 mins

comment: took too much time. did not understand the problem at first. also, 
made a mistake in set overloading and debugging took a lot of time.

tags: set operator overload
*/
