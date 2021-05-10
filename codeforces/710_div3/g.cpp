#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
vector<int> pos[26];
bool taken[26];

string func(int pp) {
    for(int i = 25; i >= 0; i--) {
        if(pos[i].size() == 0) continue;
        if(taken[i]) continue;
        /// try to place this character
        auto it = lower_bound(pos[i].begin(), pos[i].end(), pp);
        if(it == pos[i].end()) {
            continue;
        }
        bool chk = 1;
        int np = *it;
        for(int j = 25; j >= 0; j--) {
            if(pos[j].size() == 0 || taken[j]) continue;
            if(pos[j].back() < np) {chk = 0; break;}
        }
        if(chk) {
            taken[i] = 1;
            char place = i + 'a';
            return place + func(np + 1);
        }
    }
    return "";
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> str;
        for(int i = 0; i <= 25; i++) {
            pos[i].clear(); taken[i] = 0;
        }
        for(int i = 0; i < str.size(); i++) {
            pos[str[i] - 'a'].push_back(i);
        }
        cout << func(0) << endl;
    }
    return 0;
}
/**
 * 
*/
