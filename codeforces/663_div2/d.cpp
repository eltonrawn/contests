#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string str[SZ], tmp[SZ];

bool is_val(int mask1, int mask2) {
    int prev = 0;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        if(mask1 & (1 << i)) cur++;
        if(mask2 & (1 << i)) cur++;
        if(i > 0 && (prev + cur) % 2 == 0) {
            return 0;
        }
        prev = cur;
    }
    return 1;
}

int get_cost(int mask, int col) {
    int cc = 0;
    for(int i = 0; i < n; i++) {
        if((bool)(mask & (1 << i)) != (str[i][col] - '0')) {
            cc++;
        }
    }
    return cc;
}

int dp[SZ][8];

int func(int col, int prev_mask) {
    // cout << "state : " << col << " " << prev_mask << " " << is_ev1 << " " << is_ev2 << endl;
    if(col == m) {
        return 0;
    }
    if(dp[col][prev_mask] != -1) {
        return dp[col][prev_mask];
    }

    int ans = INT_MAX;
    
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            int sec_mask = 0;
            if(i == 1) sec_mask |= (1 << 0);
            if(j == 1) sec_mask |= (1 << 1);
            if(n == 2) {
                int mask = sec_mask;
                if(col != 0 && !is_val(prev_mask, mask)) continue;
                ans = min(ans, get_cost(mask, col) + func(col + 1, mask));
                continue;
            }
            for(int k = 0; k <= 1; k++) {
                int mask = sec_mask;
                if(k == 1) mask |= (1 << 2);
                if(col != 0 && !is_val(prev_mask, mask)) continue;
                ans = min(ans, get_cost(mask, col) + func(col + 1, mask));
            }
        }
    }
    return dp[col][prev_mask] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    if(n > 3 && m > 3) {
        cout << -1 << endl;
        return 0;
    }
    if(n == 1 || m == 1) {
        cout << 0 << endl;
        return 0;
    }

    if(n > m) {
        /// swap it
        for(int i = 0; i < n; i++) {
            tmp[i] = str[i];
        }
        for(int j = 0; j < m; j++) {
            string yo = "";
            for(int i = 0; i < n; i++) {
                yo += tmp[i][j];
            }
            str[j] = yo;
        }
        swap(n, m);
    }

    memset(dp, -1, sizeof(dp));
    // int ans = INT_MAX;
    
    cout << func(0, 0) << endl;

    return 0;
}
/**
*/
