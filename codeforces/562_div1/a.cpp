#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
int ara[SZ];

bool chk(int inc) {
    if(inc == 0) {
        /// handle differently
        for(int i = 2; i <= n; i++) {
            if(ara[i - 1] > ara[i]) return 0;
        }
        return 1;
    }
    int past = 0;
    for(int i = 1; i <= n; i++) {
        if(past == ara[i]) continue;
        if(past < ara[i]) {
            int tmp = ara[i];

            int cur = (ara[i] + inc) % m;
            if(cur <= ara[i]) {
                /// did a cycle
                if(cur >= past) {
                    tmp = past;
                }
            }
            past = tmp; 
            continue;
        }
        /// past > ara[i]
        if((ara[i] + inc) < past) {
            return 0;
        }
        /// past stays same
    }
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }

    int lo = 0, hi = m;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(chk(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;

    return 0;
}
/**
start: 7:55 pm
idea: 8:01 pm
end: 8:17 pm

duration: 22 mins
*/
