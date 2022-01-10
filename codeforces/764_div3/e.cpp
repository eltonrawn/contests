#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string str[SZ];
string ss;
map< string, vector<int> > mp;
int dp[SZ];

int func(int pos) {
    if(dp[pos] != -1) return dp[pos];
    if(pos == ss.size()) return dp[pos] = 1;
    int ans = 0;
    string tmp = "";
    tmp += ss[pos];
    for(int i = pos + 1; i <= pos + 2 && i < m; i++) {
        tmp += ss[i];
        if(mp.find(tmp) == mp.end()) {
            continue;
        }
        ans = max(ans, func(i + 1));
    }
    return dp[pos] = ans;
}

vector< vector<int> > pr;

void bt(int pos) {
    if(pos == ss.size()) return;
    string tmp = "";
    tmp += ss[pos];
    for(int i = pos + 1; i <= pos + 2 && i < m; i++) {
        tmp += ss[i];
        if(mp.find(tmp) == mp.end()) {
            continue;
        }
        if(func(i + 1)) {
            pr.push_back(mp[tmp]);
            bt(i + 1);
            return;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> str[i];
        }
        cin >> ss;

        mp.clear();
        pr.clear();
        for(int i = 0; i <= m; i++) {
            dp[i] = -1;
        }

        for(int pp = 1; pp <= n; pp++) {
            for(int i = 0; i < m; i++) {
                string tmp = "";
                tmp += str[pp][i];
                for(int j = i + 1; j <= i + 2 && j < m; j++) {
                    tmp += str[pp][j];
                    vector<int> v = {i + 1, j + 1, pp};
                    mp[tmp] = v;
                }
            }
        }

        if(func(0) == 0) {
            cout << -1 << endl;
            continue;
        }
        // cout << "dp : " << func(0) << endl;

        bt(0);
        cout << pr.size() << endl;
        for(vector<int> vv: pr) {
            for(int v: vv) {
                cout << v << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
/**
*/