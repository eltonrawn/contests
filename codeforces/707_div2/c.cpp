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
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int n;
int ara[MX];
vector<PII> taken[5000010];
vector<int> pr;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // FastIO;
    
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &ara[i]);
    }
    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            int ss = ara[i] + ara[j];
            if(taken[ ss ].size() >= 1) {
                pr.clear();
                
                for(PII yo: taken[ss]) {
                    if(yo.F == i || yo.F == j || yo.S == i || yo.S == j) {
                    }
                    else {
                        pr.PB(yo.F);
                        pr.PB(yo.S);
                        break;
                    }
                }
                

                if(pr.size() != 2) {
                    continue;
                }

                pr.PB(i);
                pr.PB(j);
                printf("YES\n");
                for(int yo: pr) {
                    printf("%d ", yo);
                }
                return 0;
            }
            taken[ ss ].PB({i, j});
        }
    }
    printf("NO\n");
    return 0;
}
/**
*/
