#include<bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
LL dp[20][2][10];
 
LL dp_func(vector<int> digits) {
    if(digits.size() == 1)
        return digits[0] + 1;
 
    for(int i = digits.size(); i >= 0; i--) {
        for(int is_border = 0; is_border <= 1; is_border++) {
            for(int prev = 0; prev < 10; prev++) {
                dp[i][is_border][prev] = 0;
                if(i == digits.size()) {
                    dp[i][is_border][prev] = 1;
                    continue;
                }
                int ed = digits[i];
                if(is_border == 0) {
                    // can place anything
                    ed = 9;
                }
                for(int digit = 0; digit <= ed; digit++) {
                    if(digit == prev)
                        continue;
                    if(digit < ed) {
                        dp[i][is_border][prev] += dp[i + 1][0][digit];continue;
                    }
                    dp[i][is_border][prev] += dp[i + 1][is_border][digit];
                }
            }
        }
    }
    return dp[0][1][0];
}
 
LL get_ans(vector<int> digits) {
    vector<int> tmp;
    LL ans = 0;
    for(int i = 0; i < digits.size() - 1; i++) {
        tmp.push_back(9);
        ans += dp_func(tmp);
    }
    ans += dp_func(digits);
    return ans;
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
    LL ans = get_ans(num_to_vec(b));
    if(a != 0) {
        ans -= get_ans(num_to_vec(a - 1));
    }
    cout << ans << endl;
    return 0;
}
/**
*/