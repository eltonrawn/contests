#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
int ara[SZ];

bool is_asc() {
    for(int i = 2; i <= n; i++) {
        if(ara[i - 1] <= ara[i]) {
        }
        else return 0;
    }
    return 1;
}

bool is_desc() {
    for(int i = 2; i <= n; i++) {
        if(ara[i - 1] >= ara[i]) {
        }
        else return 0;
    }
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    bool is_same = 1;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(i != 1 && ara[i] != ara[i - 1]) {
            is_same = 0;
        }
    }
    if(is_same) {
        cout << -1 << endl;
        return 0;
    }
    PII ans = {-1, -1};
    int cnt = 0;
    int lim = 4;
    for(int i = 1; i <= n; i++) {
        if(cnt == lim || ans.first != -1) break;
        for(int j = i + 1; j <= n; j++) {
            if(cnt == lim) break;
            if(ara[i] == ara[j] || ans.first != -1) continue;
            cnt++;
            swap(ara[i], ara[j]);
            if(is_asc() || is_desc()) {
                swap(ara[i], ara[j]);
                continue;
            }
            ans = {i, j};
            break;
        }
    }
    if(ans.first == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}
/**
start: 4:05 pm
end: 4:31 pm
duration: 26 mins
comment: time is not bad considering this problem requires lots of case handling.
*/
