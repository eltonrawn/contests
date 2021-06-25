#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL make[20];

LL get_len(LL num) {
    LL len = 0;
    while(num) {
        len++;
        num /= 10;
    }
    return len;
}

LL get_last_char_idx(LL num) {
    LL num_len = get_len(num);
    LL made = make[num_len - 1];
    LL prev_num = 0;
    for(int i = 1; i < num_len; i++) {
        prev_num = prev_num * 10 + 9;
    }
    made += (num - prev_num) * num_len;
    return made;
}

LL get_char_idx(LL num, LL k) {
    LL made = get_last_char_idx(num);
    while(made > k) {
        num /= 10;
        made--;
    }
    return num % 10;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout); 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    LL gun = 9;
    LL sum = 0;
    for(int i = 1; i <= 18; i++) {
        sum += (gun * i);
        make[i] = sum;
        gun *= 10;
    }
    // cout << sum << endl;

    int q;
    cin >> q;
    for(int qq = 1; qq <= q; qq++) {
        LL k;
        cin >> k;
        LL lo = 1, hi = 100000000000000000LL;
        while(lo < hi) {
            LL mid = lo + (hi - lo) / 2;
            if(get_last_char_idx(mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << get_char_idx(lo, k) << endl;
    }
    return 0;
}
/**
 * 999999999999999999
 * 1688888888888888889
 * 
 * 
 * 100000000000000000
*/
