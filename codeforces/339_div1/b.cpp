#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, a, cf, cm, m;
PLL orig[SZ];
LL ara[SZ], csum[SZ];

bool is_possible(LL total, LL min_val) {
    LL lo = 0, hi = n;
    while(lo < hi) {
        LL mid = lo + (hi - lo + 1) / 2;
        if(ara[mid] < min_val) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    if((lo * min_val) - csum[lo] <= total) {
        return 1;
    }
    return 0;
}

LL get_min(LL total) {
    LL lo = 0, hi = a;
    while(lo < hi) {
        LL mid = lo + (hi - lo + 1) / 2;
        if(is_possible(total, mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> cf >> cm >> m;
    for(int i = 1; i <= n; i++) {
        cin >> orig[i].first;
        orig[i].second = i;
    }
    sort(orig + 1, orig + n + 1);
    for(int i = 1; i <= n; i++) {
        ara[i] = orig[i].first;
    }
    for(int i = 1; i <= n; i++) {
        csum[i] = ara[i] + csum[i - 1];
    }
    LL yoyo = get_min(m);
    LL ans = cm * yoyo;
    LL cnt = 0;
    LL anscnt = 0, ansmn = yoyo;
    for(int i = n; i >= 1; i--) {
        /// this has to be dynamic
        cnt++;
        if(a - ara[i] > m) break;
        m -= a - ara[i];
        ara[i] += a - ara[i];
        yoyo = get_min(m);
        if(cm * yoyo + cnt * cf > ans) {
            ans = cm * yoyo + cnt * cf;
            anscnt = cnt;
            ansmn = yoyo;
            // cout << i << " : " << ans << endl;
        }
        // cout << "mn : " << get_min(m) << " " << "total: " << m << endl;
    }
    // cout << "anscnt : " << anscnt << endl;
    
    for(int i = n; i >= 1 && anscnt; i--) {
        ara[orig[i].second] = orig[i].first = a;
        anscnt--;
    }
    for(int i = 1; i <= n; i++) {
        if(orig[i].first < ansmn) {
            ara[orig[i].second] = ansmn;
        }
        else {
            ara[orig[i].second] = orig[i].first;
        }
    }

    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;
    return 0;
}
/**
start: 8:19 pm
end: 9:17 pm
duration: 1 hour. 
comment: really need to solve these problems faster.
*/
