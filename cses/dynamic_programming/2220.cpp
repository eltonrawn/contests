#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL dp[20][2][11][2];

LL dp_func(vector<int> digits) {
    for(int i = digits.size(); i >= 0; i--) {
        for(int is_border = 0; is_border < 2; is_border++) {
            for(int prev = 0; prev <= 9; prev++) {
                for(int is_start = 0; is_start < 2; is_start++) {
                    dp[i][is_border][prev][is_start] = 0;
                    if(i == digits.size()) {
                        dp[i][is_border][prev][is_start] = 1;
                        continue;
                    }
                    int ed = digits[i];
                    if(is_border == 0) {
                        // can place anything
                        ed = 9;
                    }
                    for(int digit = 0; digit <= ed; digit++) {
                        if(digit == prev && (digit != 0 || is_start))
                            continue;
                        int nxt_start = 1;
                        if(is_start == 0 && digit == 0)
                            nxt_start = 0;
                        if(digit < ed) {
                            dp[i][is_border][prev][is_start] += dp[i + 1][0][digit][nxt_start];
                            continue;
                        }
                        dp[i][is_border][prev][is_start] += dp[i + 1][is_border][digit][nxt_start];
                    }
                }
            }
        }
    }
    return dp[0][1][0][0];
}

vector<int> num_to_vec(LL num) {
    vector<int> vec;
    if(num == 0) {
        vec.push_back(num); return vec;
    }
        
    while(num) {
        vec.push_back(num % 10);
        num /= 10;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL a, b;
    cin >> a >> b;
    LL ans = dp_func(num_to_vec(b));
    if(a != 0) {
        ans -= dp_func(num_to_vec(a - 1));
    }
    cout << ans << endl;
    return 0;
}
/**
*/
