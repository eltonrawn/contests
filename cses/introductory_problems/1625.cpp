#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

bool vis[9][9];
// string str;
char str[50];
int ans;

void bt(int pos, int x, int y) {
    if(x == 7 && y == 1) {
        if(pos == 48)
            ans++;
        return;
    }
    if(pos == 48) return;

    if(pos + abs(x - 7) + abs(y - 1) > 48) {
        return;
    }

    int p1 = 0;
    int p2 = 2;
    // cout << p1 << " " << (p1 ^ 1) << endl;
    // cout << p2 << " " << (p2 ^ 1) << endl;
    if(vis[x + dirx[p1]][y + diry[p1]] == vis[x + dirx[p1 ^ 1]][y + diry[p1 ^ 1]] && 
    vis[x + dirx[p2]][y + diry[p2]] == vis[x + dirx[p2 ^ 1]][y + diry[p2 ^ 1]] &&
    vis[x + dirx[p1]][y + diry[p1]] != vis[x + dirx[p2]][y + diry[p2]]) {
        // cout << "hi" << endl;
        return;
    }
        
    
    vis[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        if((str[pos] == '?' || str[pos] == dir[i]) && !vis[x + dirx[i]][y + diry[i]])
            bt(pos + 1, x + dirx[i], y + diry[i]);
        
    }

    vis[x][y] = 0;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    scanf("%s", str);
    // str = ch;
    for(int i = 0; i <= 8; i++) {
        for(int j = 0; j <= 8; j++) {
            if(i == 0 || i == 8 || j == 0 || j == 8)
                vis[i][j] = 1;
        }
    }
    // cout << bt(0, 1, 1) << endl;
    bt(0, 1, 1);
    printf("%d\n", ans);
    return 0;
}
/**
??????R
??????U
???????
???????
???????
?????LD
????D?

00
01

10
11
*/
