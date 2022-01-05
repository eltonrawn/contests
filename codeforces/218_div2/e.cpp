#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
PLL ara[SZ];
LL csum[SZ];
LL get_pair_dis(int le, int ri) {
    LL ans = 0;
    for(int i = le; i <= ri; i++) {
        for(int j = i + 1; j <= ri; j++) {
            ans += ara[j].first - ara[i].first;
        }
    }
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i].first;
        ara[i].second = i;
        // csum[i] = csum[i - 1] + ara[i].first;
    }
    cin >> k;
    sort(ara + 1, ara + 1 + n);

    for(int i = 1; i <= n; i++) {
        csum[i] = csum[i - 1] + ara[i].first;
    }

    LL ans = INT_MAX;
    LL ans_pos;

    LL sum_till_last = 0;
    LL all_sum = 0;
    for(int i = 2; i <= k; i++) {
        sum_till_last += (ara[i].first - ara[i - 1].first) * (i - 1);
        all_sum += sum_till_last;
    }

    ans = all_sum;
    ans_pos = 1;

    for(int i = k + 1; i <= n; i++) {
        /// remove i - k
        all_sum -= (csum[i - 1] - csum[i - k]) - (ara[i - k].first * (k - 1LL));
        sum_till_last -= ara[i - 1].first - ara[i - k].first;

        /// add i
        sum_till_last += (ara[i].first - ara[i - 1].first) * (k - 1);
        all_sum += sum_till_last;
        if(all_sum < ans) {
            ans = all_sum;
            ans_pos = i - k + 1;
        }
    }

    for(int i = ans_pos; i <= ans_pos + k - 1; i++) {
        cout << ara[i].second << " ";
    }
    // cout << ans << " " << get_pair_dis(ans_pos, ans_pos + k - 1) << endl;
    cout << endl;
    return 0;
}
/**
start: 1:55 pm
comment: solved one day later. I don't want to solve when it involves mathematial calculation. don't be lazy.
also did a silly mistake. bad performance.
*/
