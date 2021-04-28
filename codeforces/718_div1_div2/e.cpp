#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
LL ara[SZ];
LL total, valid;
LL ans;
vector<LL> even, odd;

LL get_ans(int start, LL sum, int jend) {
    LL ret = 0;
    for(int i = start; i < n; i++) {
        sum += ara[i];
        if(sum > valid) {
            break;
        }
        ret++;
        ret %= MOD;

        if(i % 2) {
            /// odd
            int lo = i + 2;
            int hi = jend - 1;
            // if(lo > hi) {
            //     continue;
            // }
            while(lo < hi) {
                int mid = lo + ((hi - lo + 1) / 2);
                if(sum - (odd[i + 1]) + odd[mid] > valid) {
                    hi = mid - 1;
                }
                else {
                    lo = mid;
                }
            }
            if(lo % 2 == 0) {
                lo--;
            }
            if(sum - (odd[i + 1]) + odd[lo] <= valid) {
                
                if(lo >= i + 2 && lo <= jend - 1) {
                    ret += max(0, (lo - (i + 2) + 2) / 2);
                    ret %= MOD;
                }
            }
            
        }
        else {
            /// even
            int lo = i + 2;
            int hi = jend - 1;
            // if(lo > hi) {
            //     continue;
            // }
            while(lo < hi) {
                int mid = lo + ((hi - lo + 1) / 2);
                if(sum - (even[i + 1]) + even[mid] > valid) {
                    hi = mid - 1;
                }
                else {
                    lo = mid;
                }
            }

            if(lo % 2) {
                lo--;
            }
            if(sum - (even[i + 1 ]) + even[lo] <= valid) {   
                if(lo >= i + 2 && lo <= jend - 1) {
                    ret += max(0, (lo - (i + 2) + 2) / 2);
                    ret %= MOD;
                }
            }
        }
        
        // LL tmp = sum;
        // for(int j = i + 2; j < jend; j += 2) {
        //     tmp += ara[j];
        //     if(tmp > valid) {
        //         break;
        //     }
        //     ret++;
        // }
    }
    // cout << "ret : " << start << " " << ret << endl;
    return ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        total = 0;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
            total += ara[i];
            // csum[i] = total;
        }
        valid = (total - 1) / 2;
        ans = 0;
        LL sum = 0;
        for(int i = n; i >= min(3, n); i--) {
            sum += ara[i];
            if(sum > valid) {
                break;
            }
            ans++;
        }

        // cout << "valid : " << valid << endl;
        // cout << "suffix : " << ans << endl;
        
        even.clear();odd.clear();
        even.push_back(0);odd.push_back(0);
        sum = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0) {
                odd.push_back(sum);
                continue;
            }
            sum += ara[i];
            odd.push_back(sum);
        }
        sum = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2) {
                even.push_back(sum);
                continue;
            }
            sum += ara[i];
            even.push_back(sum);
        }

        ans += get_ans(1, 0, n);
        ans += get_ans(1, ara[n], n - 1);
        

        ans += get_ans(2, 0, n);
        ans += get_ans(2, ara[n], n - 1);
        ans %= MOD;

        cout << ans + 1 << endl;
        /// (12 - 1) / 2 -> 5 + 7 (13 - 1) / 2 -> 6 + 7
    }
    return 0;
}
/**
 * 
 * 184688892
 * 2 1 2 1 1
 * 
 * valid: 3
 * 
 * 2 X X X X RR
 * 2 1 X X X RR
 * 
 * 2 X X X 1 RR
 * 
 * X 1 X X X RR
 * X 1 X 1 X RR
 * X 1 2 X X RR
 * 
 * X 1 X X 1 RR
 * X 1 X 1 1 
 * 
 * X X X X 1 RR
 * X X X 1 1 RR
 * 
 * 1 2 3 4    5 6 7 8 9 10
 * 2 4          6 8 10
 * 
 * 1 2 3 4 5      6 7 8 9 10
 * 1 3 5            7 9
 * 
 * 
 * /// for odd
 * 1 2 3 4 5 6 7
 * hi = 5 size() - 2
 * 1 2 3 4 5 6
 * hi = 5 // size() - 1
 * hi = 3 // size() - 2
 * 
*/


/**
 * 19 20 21 22  24  26  28
 *            23  25  27  29 30 31 32 33
 * 19 20 21 22  24  26  28  30  32  34
 *            23  25  27  29  31  33
 * 
 * 19 20 21 22  24  26  28              34
 *            23  25  27  29 30 31 32 33
 * 
 *   24 25 26  28  30  32           37
 * 23        27  29  31  33 34 35 36
 * 
 *            25 26 27
 * 21 22 23 24
 * 
 * valid -> sum is less than total / 2
 * ans = 0
 * 1. take all possible valid suffix excluding 1st 2 numbers -> ans
 * 
 * 2. start from 1st element
 *      take valid prefix excluding last number
 *          take valid inverted(either even or odd, determined by prefix) prefix -> ans
 *      take valid prefix and include last number
 *          take valid inverted prefix -> ans
 * 
 * 3. start from 2nd element
 *      take valid prefix excluding last number
 *          take valid inverted(either even or odd, determined by prefix) prefix -> ans
 *      take valid prefix and include last number
 *          take valid inverted prefix -> ans
 * 
 * 100 2 3
 * 
*/
