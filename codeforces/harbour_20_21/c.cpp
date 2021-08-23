#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
int ans = 10;

int goal[2];

void calc_ans(int pos) {
    int chance[2];
    memset(chance, 0, sizeof(chance));
    for(int i = 1; i <= pos; i += 2) {
        chance[0]++;
    }
    for(int i = 2; i <= pos; i += 2) {
        chance[1]++;
    }
    // if(goal[1] == 1 && chance[0] == 5) cout << "hi" << endl;
    // if(pos == 9)
    //     cout << goal[1] << " " << chance[0] << endl;
    if(goal[0] > goal[1] + (5 - chance[1])) ans = min(ans, pos);
    if(goal[1] > goal[0] + (5 - chance[0])) ans = min(ans, pos);
}

void func(int pos, bool turn) {
    if(pos != 1)
        calc_ans(pos - 1);
    
    if(pos == 11) {
        return;
    }
    
    if(str[pos] == '1' || str[pos] == '?') {
        goal[turn]++;
        func(pos + 1, !turn);
        goal[turn]--;
    }
    if(str[pos] == '0' || str[pos] == '?') {
        func(pos + 1, !turn);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> str;
        str = "?" + str;
        // memset(goal, 0, sizeof(goal));
        ans = 10;
        func(1, 0);
        cout << ans << endl;
    }
    return 0;
}
/**
*/
