#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int n, m, q;
string str[SZ];
int ans[SZ][SZ], vis[SZ][SZ];

int get_ans(int x, int y) {
    if(vis[x][y]) return 0;
    vis[x][y] = 1;
    int foo = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + fx[i];
        int ny = y + fy[i];
        if(str[nx][ny] == '*') {
            foo++;
        }
        else {
            foo += get_ans(nx, ny);
        }
    }
    return foo;
}

void set_ans(int x, int y, int val) {
    if(vis[x][y]) return;
    vis[x][y] = 1;
    ans[x][y] = val;

    for(int i = 0; i < 4; i++) {
        int nx = x + fx[i];
        int ny = y + fy[i];
        if(str[nx][ny] == '*') {}
        else {
            set_ans(nx, ny, val);
        }
    }
}

void clear_vis(int x, int y) {
    if(vis[x][y] == 0) return;
    vis[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + fx[i];
        int ny = y + fy[i];
        if(str[nx][ny] == '*') {}
        else {
            clear_vis(nx, ny);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m >> q;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = -1;
            }
        }

        for(int i = 1; i <= q; i++) {
            int x, y;
            cin >> x >> y;
            x--;y--;
            if(ans[x][y] != -1) {
                cout << ans[x][y] << endl;
                continue;
            }
            int val = get_ans(x, y);
            // cout << "val : " << val << endl;
            clear_vis(x, y);
            set_ans(x, y, val);
            clear_vis(x, y);
            cout << ans[x][y] << endl;
        }
    // }
    return 0;
}
/**
*/
