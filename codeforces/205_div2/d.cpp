#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1000010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
LL boys[SZ];
vector<int> girls;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // convert the problem so that a girl initially waits and then moves all at once
    // instead of moving when she has chance, wait and move again like in the problem
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(i != 0) boys[i] += boys[i - 1];
        if(str[i] == 'M') boys[i]++;
        else {
            girls.push_back(i);
        }
    }
    LL wait_time = 0;
    LL ans = 0;
    for(int i = 0; i < girls.size(); i++) {
        int idx = girls[i];
        if(i == 0 || boys[idx] == 0) {
            ans = boys[idx];
            continue;
        }
        wait_time = max(0LL, wait_time + 1 - (boys[idx] - boys[girls[i - 1]]));
        ans = max(ans, wait_time + boys[idx]);
    }
    cout << ans << endl;
    return 0;
}
/**
start: 11:16 am
end: 11:54 am
duration: 38 mins
comment: not bad considering thinking took some time.
*/
