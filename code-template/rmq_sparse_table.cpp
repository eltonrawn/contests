#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;



int n;
int ara[SZ];
int mylog[SZ];
int st[SZ][40];

void init_sparse() {
    mylog[1] = 0;
    for (int i = 2; i <= n; i++)
        mylog[i] = mylog[i/2] + 1;
    
    for (int i = 0; i < n; i++)
        st[i][0] = ara[i];

    for (int j = 1; j <= 25; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
            
        }
    }

}

int get_min(int l, int r) {
    int j = mylog[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}