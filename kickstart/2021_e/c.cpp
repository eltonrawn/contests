#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 1010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string str[SZ];
int le[SZ][SZ], ri[SZ][SZ], up[SZ][SZ], down[SZ][SZ];
bool vis[SZ][SZ];
int ans;

void process_all(int srcx, int srcy) {
    
    // cout << "src : " << srcx << " " << srcy << endl;

    queue<PII> q;
    q.push({srcx, srcy});
    vis[srcx][srcy] = 1;

    while(!q.empty()) {
        PII top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        int mn;

        /// check vertical
        mn = min(y - le[x][y], ri[x][y] - y);
        int ny = (le[x][y] + mn == y) ? ri[x][y] - mn : le[x][y] + mn;
        // cout << "ny : " << x << " " << y << " : " << ny << endl;
        if(!vis[x][ny] && (str[x][ny] == '.')) {
            vis[x][ny] = 1;
            str[x][ny] = str[x][y]; ans++;
            q.push({x, ny});
        }

        /// check horizontal
        mn = min(x - up[x][y], down[x][y] - x);
        int nx = (up[x][y] + mn == x) ? down[x][y] - mn : up[x][y] + mn;
        // cout << "nx : " << x << " " << y << " : " << nx << endl;
        if(!vis[nx][y] && str[nx][y] == '.') {
            vis[nx][y] = 1;
            str[nx][y] = str[x][y]; ans++;
            q.push({nx, y});
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            string tmp; cin >> tmp;
            str[i] = " " + tmp;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                le[i][j] = 0;
                ri[i][j] = 0;
                up[i][j] = 0;
                down[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            int past = 0;
            for(int j = 1; j <= m; j++) {
                if(str[i][j] == '#') {past = 0; continue;}
                if(past == 0) past = j;
                le[i][j] = past;
            }
        }
        for(int i = 1; i <= n; i++) {
            int past = 0;
            for(int j = m; j >= 1; j--) {
                if(str[i][j] == '#') {past = 0; continue;}
                if(past == 0) past = j;
                ri[i][j] = past;
            }
        }

        for(int j = 1; j <= m; j++) {
            int past = 0;
            for(int i = 1; i <= n; i++) {
                if(str[i][j] == '#') {past = 0; continue;}
                if(past == 0) past = i;
                up[i][j] = past;
            }
        }
        
        for(int j = 1; j <= m; j++) {
            int past = 0;
            for(int i = n; i >= 1; i--) {
                if(str[i][j] == '#') {past = 0; continue;}
                if(past == 0) past = i;
                down[i][j] = past;
            }
        }

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 1; j <= m; j++) {
        //         cout << down[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i][j] || str[i][j] == '#' || str[i][j] == '.') continue;
                process_all(i, j);
            }
        }

        cout << "Case #" << tt << ": " << ans << endl;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << str[i][j];
            }
            cout << endl;
        }

    }
    return 0;
}
/**
*/
