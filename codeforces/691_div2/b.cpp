#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

/// up, right, down, left
int fx[] = {-1, 0, +1, 0};
int fy[] = {0, 1, 0, -1};


map<pair<int, int>, int> mp;
int n;
queue< pair < pair < int, int >, pair < int, int > > > q;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;


    // q.push({{1, 1}, {0, 0}});
    // q.push({{1, 1}, {1, 0}});
    // while(!q.empty()) {
    //     pair < pair < int, int >, pair < int, int > > top = q.front();
    //     q.pop();
    //     int x = top.first.first;
    //     int y = top.first.second;
    //     int orien = top.second.first;
    //     int len = top.second.second;
    //     if(mp[{x, y}]) continue;
    //     if(len > n) continue;
    //     mp[{x, y}] = 1;

    //     int pp, nx, ny;
        
    //     pp = orien - 1 == -1 ? 3 : orien - 1;
    //     nx = x + fx[pp];
    //     ny = y + fy[pp];
    //     q.push({{nx, ny}, {pp, len + 1}});

    //     pp = orien + 1 == 4 ? 0 : orien - 1;
    //     nx = x + fx[pp];
    //     ny = y + fy[pp];
    //     q.push({{nx, ny}, {pp, len + 1}});

    // }

    int ans;
    if(n % 2) {
        int cell = n + 2;
        ans = (cell * cell) / 2;
    }
    else {
        int gun = (n / 2) + 1;
        ans = gun * gun;
    }

    cout << ans << endl;

    return 0;
}
/**
*/
