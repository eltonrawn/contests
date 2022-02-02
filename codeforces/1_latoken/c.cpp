#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 400010
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

int n;
int a[SZ];
int b[SZ];
set<int> st;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        make_set(n);
        for(int i = 1; i <= n; i++) {
            if(!is_uni(a[i], b[i]))
                union_node(a[i], b[i]);
        }
        
        st.clear();
        for(int i = 1; i <= n; i++) {
            st.insert(find_rep(i));
            // cout << i << " : " << find_rep(i) << endl;
        }
        LL ans = 1;
        for(int i = 1; i <= st.size(); i++) {
            ans *= 2;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
*/
