#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int n, m;
LL ara[310][310], orig[310][310];

bool valid(int x, int y) {
    if(x >= 1 && x <= n && y >= 1 && y <= m) {
        return 1;
    }
    return 0;
}

void reset_ara() {
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            ara[i][j] = orig[i][j];
        }
    }
}

void print_ara() {
    cout << "------------->print ara : \n";
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << ara[i][j] << " ";
        }
        cout << "\n";
    }
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << (i + j) % 2 << " ";
        }
        cout << "\n";
    }
}

int propogate(int i, int j, int yoyo) {
    int ans = 0;
    FOR(k, 0, 3) {
        int nx = i + fx[k];
        int ny = j + fy[k];
        if(!valid(nx, ny) || ara[nx][ny] >= yoyo) {
            continue;
        }
        ans += yoyo - 1 - ara[nx][ny];
        // cout << i << " " << j << " : " << ara[nx][ny] << " " << yoyo - 1 << endl;
        ara[nx][ny] = yoyo - 1;
    }
    return ans;
}

LL solve(int mx) {
    reset_ara();
    // cout << "solve ------------------->\n";

    LL ans = 0;

    for(int vv = mx; vv >= 0; vv--) {
        
        LL mn = LLONG_MAX;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                mn = min(mn, ara[i][j]);
            }
        }

        // cout << "vv : " << vv << " " << mn << " " << cnt << endl;
        if(mn > vv) {
            break;
        }

        FOR(i, 1, n) {
            FOR(j, 1, m) {
                int col = (i + j) % 2;
                if(ara[i][j] == vv) {
                    ans += propogate(i, j, ara[i][j]);
                }
            }
        }
    }
    // print_ara();
    // cout << "res : " << ans << endl;
    return ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> m;
        LL mx = 0;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                cin >> orig[i][j];
                mx = max(mx, orig[i][j]);
            }
        }
        cout << "Case #" << tt << ": ";
        cout << solve(mx) << endl;
        // print_ara();
    }
    return 0;
}
/**
 * 
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
*/
