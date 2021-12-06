#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, x;
LL ara[SZ], nara[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    x--;
    LL mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> ara[i];
        mn = min(ara[i], mn);
    }
    int mnpos;
    for(int i = x + 1; ; i++) {
        i = i % n;
        if(mn == ara[i]) mnpos = i;
        if(i == x) {
            break;
        }
    }

    LL val = ara[mnpos] + 1;
    LL tmp = 0;
    if(mnpos == x) val--;
    for(int i = mnpos + 1; ; i++) {
        i = i % n;
        if(i == mnpos) {
            break;
        }
        nara[i] = ara[i] - val;
        tmp += val;
        // cout << i << " : " << val << endl;
        if(i == x) {
            val--;
        }
    }
    nara[mnpos] = tmp + ara[mnpos];
    for(int i = 0; i < n; i++) {
        cout << nara[i] << " ";
    }
    cout << endl;
    return 0;
}
/**
start: 7:39 pm
end: 8:19 pm
duration: 40 mins
took time because statement was confusing
*/
