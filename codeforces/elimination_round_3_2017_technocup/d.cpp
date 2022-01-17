#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
string str[SZ];
int cost[SZ];
set<string> pal_st, non_pal_st;
map<string, vector<int>> pal_mp, non_pal_mp;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tmp;
    cin >> n >> tmp;
    for(int i = 1; i <= n; i++) {
        cin >> str[i] >> cost[i];
        // unq_str.insert(str[i]);
        string rev = str[i];
        reverse(rev.begin(), rev.end());
        if(str[i] == rev) {
            pal_st.insert(str[i]);
            pal_mp[str[i]].push_back(cost[i]);
        }
        else {
            non_pal_st.insert(str[i]);
            non_pal_mp[str[i]].push_back(cost[i]);
        }
    }
    LL ans = 0;
    for(string ss: non_pal_st) {
        string rev = ss;
        reverse(rev.begin(), rev.end());
        vector<int> v1 = non_pal_mp[ss];
        vector<int> v2 = non_pal_mp[rev];
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end(), greater<int>());
        for(int i = 0; i < min(v1.size(), v2.size()); i++) {
            if(v2[i] + v1[i] > 0) {
                ans += v1[i] + v2[i];
            }
        }
        non_pal_mp[ss].clear();
        non_pal_mp[rev].clear();
    }
    // cout << "init_ans " << ans << endl;

    vector<int> negative, single;
    for(string ss: pal_st) {
        vector<int> v1 = pal_mp[ss];
        sort(v1.begin(), v1.end());
        while(v1.size() >= 2) {
            int foo1 = v1.back();
            if(foo1 < 0) break;
            v1.pop_back();
            int foo2 = v1.back();
            if(foo2 < 0) {
                if(foo1 + foo2 > 0) {
                    // this has the potential to be single
                    negative.push_back(-1 * foo2);
                }
                else {
                    single.push_back(foo1);
                    break;
                }
            }
            v1.pop_back();
            ans += foo1 + foo2;
        }
        if(!v1.empty()) {
            int foo1 = v1.back();
            if(foo1 > 0) single.push_back(foo1);
        }
        pal_mp[ss].clear();
    }
    // cout << "mid_ans " << ans << endl;
    sort(negative.begin(), negative.end());
    sort(single.begin(), single.end());
    if(!negative.empty() && !single.empty()) {
        if(negative.back() >= single.back()) {
            ans += negative.back();
        }
        else {
            ans += single.back();
        }
    }
    else if(!negative.empty()) {
        ans += negative.back();
    }
    else if(!single.empty()) {
        ans += single.back();
    }
    cout << ans << endl;

    return 0;
}
/**
start: 3:33 pm
*/
