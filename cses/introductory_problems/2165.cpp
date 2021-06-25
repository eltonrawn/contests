#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

vector<PII> vv;

void toh(int n, int src, int middle, int target) {
    if(n == 0) return;
    /// move n - 1 disks from src to middle
    toh(n - 1, src, target, middle);
    /// move n th disks to target
    vv.push_back({src, target});
    /// move n - 1 disks from middle to target
    toh(n - 1, middle, src, target);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    toh(n, 1, 2, 3);
    cout << vv.size() << endl;
    for(PII val: vv)
        cout << val.first << " " << val.second << endl;
    return 0;
}
/**
*/
