#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 110
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int n;
int ara[SZ];

vector<int> adjl[SZ];

int get_max_pos(int le, int ri) {
    int mx = 0;
    int mxpos = 0;
    for(int i = le; i <= ri; i++) {
        if(ara[i] > mx) {
            mx = ara[i];
            mxpos = i;
        }
    }
    return mxpos;
}

void func(int le, int ri, int par) {
    if(le > ri) return;
    int mxpos = get_max_pos(le, ri);

    if(par != 0)
        adjl[par].push_back(mxpos);

    func(le, mxpos - 1, mxpos);
    func(mxpos + 1, ri, mxpos);
}

int depth[SZ];
void ff(int u, int par, int dd) {
    for(int v: adjl[u]) {
        if(v == par) continue;
        ff(v, u, dd + 1);
    }
    depth[u] = dd;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        for(int i = 1; i <= n; i++) {
            adjl[i].clear();
        }
        func(1, n, 0);
        ff(get_max_pos(1, n), 0, 0);
        for(int i = 1; i <= n; i++)
            cout << depth[i] << " ";

        cout << endl;
    }
    return 0;
}
/**
*/
