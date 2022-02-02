#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
vector<int> ara[SZ];

int get_winner(int a, int b) {
    int win = 0;
    for(int i = 0; i < 5; i++) {
        if(ara[a][i] < ara[b][i]) win++;
    }
    if(win >= 3) return a;
    return b;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            ara[i].clear();
            for(int j = 0; j < 5; j++) {
                int tmp; cin >> tmp;
                ara[i].push_back(tmp);
            }
        }
        int winner = 1;
        for(int i = 2; i <= n; i++) {
            winner = get_winner(winner, i);
        }
        bool chk = 1;
        for(int i = 1; i <= n; i++) {
            if(i == winner) continue;
            if(winner != get_winner(winner, i)) {
                chk = 0; break;
            }
        }
        cout << (chk ? winner : -1) << endl;
    }
    return 0;
}
/**
*/
