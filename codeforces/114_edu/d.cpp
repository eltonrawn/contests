#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> vv[SZ];

int m;
vector<int> bad[SZ];
map< vector<int>, int> bad_mp, taken;

vector< vector<int> > processed;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int val; cin >> val;
            vv[i].push_back(val);
        }
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int val; cin >> val;
            val--;
            bad[i].push_back(val);
        }
        bad_mp[bad[i]] = 1;
    }

    // for(auto i: bad_mp) {
    //     vector<int> cur = i.first;
    //     for(int val: cur) cout << val << " ";
    //     cout << endl;
    // }
    
    vector<int> init;
    int init_sum = 0;
    for(int i = 0; i < n; i++) {
        init_sum += vv[i].back();
        init.push_back(vv[i].size() - 1);
    }
    
    taken[init] = 1;
    processed.push_back(init);
    

    set< pair<int, int> > st;
    st.insert({0, processed.size() - 1});

    while(!st.empty()) {
        pair<int, int> top = *st.begin();
        st.erase(st.begin());
        vector<int> cur = processed[top.second];
        
        // cout << "cur ";
        // for(int val: cur) cout << val + 1 << " ";
        // cout << ": " << bad_mp[cur] << endl;
        
        if(!bad_mp[cur]) {
            for(int val: cur) cout << val + 1 << " ";
            cout << endl;
            break;
        }

        int sum = 0;
        for(int i = 0; i < cur.size(); i++) sum += vv[i][cur[i]];

        for(int i = 0; i < cur.size(); i++) {
            if(cur[i] == 0) continue;
            sum -= vv[i][cur[i]];
            cur[i]--;
            sum += vv[i][cur[i]];
            
            if(!taken[cur]) {
                taken[cur] = 1; processed.push_back(cur);
                st.insert({init_sum - sum, processed.size() - 1});
            }
            
            sum -= vv[i][cur[i]];
            cur[i]++;
            sum += vv[i][cur[i]];
        }

    }

    return 0;
}
/**
*/
