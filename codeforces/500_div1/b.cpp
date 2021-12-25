#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

/************************* disjoint set start ***************************************/
int par[SZ];
int rank_of[SZ];
void make_set(int nein)	{
    for (int i = 0; i <= nein; i++)	{
        par[i] = i;
        rank_of[i] = 0;
    }
}
int find_rep(int i)	{
    if (i != par[i])	{
        par[i] = find_rep(par[i]);
    }
    return par[i];
}
bool is_uni(int u, int v)	{// is it union
    int par_u = find_rep(u);
    int par_v = find_rep(v);
    if (par_u == par_v)	{
        return true;
    }
    return false;
}
void union_node(int u, int v)	{
    int par_u = find_rep(u);
    int par_v = find_rep(v);
    if (par_u == par_v)	{   //this means they are in same set
        return;
    }
    if (rank_of[par_u] == rank_of[par_v])	{
        rank_of[par_u]++;
        par[par_v] = par_u;
    }
    else if (rank_of[par_u] > rank_of[par_v])	{
        par[par_v] = par_u;
    }
    else	{
        par[par_u] = par_v;
    }
}
/************************* disjoint set end ***************************************/

int n, m, q;
PII ara[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int tc;
    // cin >> tc;
    // for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m >> q;
        for(int i = 1; i <= q; i++) {
            cin >> ara[i].first >> ara[i].second;
        }
        /// make set on columns
        make_set(m);

        sort(ara + 1, ara + q + 1);

        int unique_rows = 0;
        for(int i = 1; i <= q; i++) {
            unique_rows++;
            int j = i;
            while(j <= q && ara[i].first == ara[j].first) {
                /// union on columns
                union_node(ara[i].second, ara[j].second);
                j++;
            }
            i = j - 1;
        }
        set<int> unique_cols;
        for(int i = 1; i <= m; i++) {
            unique_cols.insert(find_rep(i));
        }
        cout << unique_cols.size() - 1 + (n - unique_rows) << endl;

    // }
    return 0;
}
/**
start: 1:45 pm
coding: 2:30 pm
end: 2:43 pm
duration: 1 hr
comment: disappointing as finding solution took time.
tags: disjoint set union
*/
