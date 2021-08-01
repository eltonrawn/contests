#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
int ara[SZ];
map<int, int> freq;
int cnt;
int ans;

void ins_freq(int val) {
    freq[val]++;
    if(freq[val] == 1) cnt++;
}

void rem_freq(int val) {
    freq[val]--;
    if(freq[val] == 0) cnt--;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> ara[i];
    
    
    for(int ri = 1; ri <= k; ri++) {
        ins_freq(ara[ri]);
    }
    ans = cnt;

    int le = 1;
    for(int ri = k + 1; ri <= n; ri++) {
        rem_freq(ara[ri - k]);
        ins_freq(ara[ri]);
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
/**
*/
