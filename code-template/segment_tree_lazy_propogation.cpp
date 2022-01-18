#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class Data  {
public:
    LL lazy, sum;
    Data()  {lazy = 0; sum = 0;}
};

class Segtree {
public:
    vector<Data> tree;

    Segtree() {}

    Segtree(int sz) {
        for(int i = 0; i <= sz * 4; i++)
            tree.push_back(Data());
    }

    void update_node(int node, int le_ran, int ri_ran, LL lazy)    {
        tree[node].sum += ((ri_ran - le_ran + 1LL) * lazy);
        tree[node].lazy += lazy;
    }
    
    void lazy_update(int node, int le_ran, int ri_ran)    {
        if(le_ran == ri_ran) return;
        int mid = (le_ran + ri_ran) / 2;
        update_node(node * 2, le_ran, mid, tree[node].lazy);
        update_node((node * 2) + 1, mid + 1, ri_ran, tree[node].lazy);
        tree[node].lazy = 0;
    }
    
    void update(int node, int le_ran, int ri_ran, int le, int ri, LL val)  {
        ///not in range
        if((ri_ran < le) || (le_ran > ri)) return;
        
        ///completely in range
        if((le_ran >= le) && (ri_ran <= ri)) {
            update_node(node, le_ran, ri_ran, val);
            return;
        }

        lazy_update(node, le_ran, ri_ran);
    
        int mid = (le_ran + ri_ran) / 2;
        update(node * 2, le_ran, mid, le, ri, val);
        update(node * 2 + 1, mid + 1, ri_ran, le, ri, val);
        tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
    }
    
    LL query(int node, int le_ran, int ri_ran, int le, int ri)  {///ran = range
        ///not in range
        if((ri_ran < le) || (le_ran > ri)) return 0;

        ///completely in range
        if((le_ran >= le) && (ri_ran <= ri)) return tree[node].sum;

        lazy_update(node, le_ran, ri_ran);
    
        int mid = (le_ran + ri_ran) / 2;
        LL v1 = query(node * 2, le_ran, mid, le, ri);
        LL v2 = query((node * 2) + 1, mid + 1, ri_ran, le, ri);
        return v1 + v2;
    }

};


int n, q;
vector<int> adjl[SZ];
int grp[SZ], pos[SZ], lim[SZ];

int func(int u, int par, int pp, int grp_no) {
    int sz = 1;
    for(int v: adjl[u]) {
        if(v == par) continue;
        sz += func(v, u, pp + 1, grp_no);
    }
    grp[u] = grp_no;
    pos[u] = pp;
    return sz;
}

Segtree tree[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
    
    // func(1, 0);
    int mx_lim = 0;
    int grp_no = 1;
    grp[1] = grp_no;
    pos[1] = 1;
    for(int v: adjl[1]) {
        grp_no++;        
        lim[grp_no] = func(v, 1, 1, grp_no);
        mx_lim = max(mx_lim, lim[grp_no]);
    }
    lim[1] = mx_lim + 1;

    for(int i = 1; i <= grp_no; i++) {
        tree[i] = Segtree(lim[i]);
    }

    for(int i = 1; i <= q; i++) {
        // cout << "qq : " << i << endl;
        int cmd; cin >> cmd;
        if(cmd == 0) {
            int v, x, d;
            cin >> v >> x >> d;
            if(v == 1) {
                int ri = lim[1];
                tree[1].update(1, 1, ri, 1, min(lim[1], pos[v] + d), x);
                // cout << "update " << grp[v] << " " << 1 << " " << min(lim[1], pos[v] + d) << " : " << x << endl;
            }
            else {
                int ri = lim[grp[v]];
                tree[grp[v]].update(1, 1, ri, max(1, pos[v] - d), min(lim[grp[v]], pos[v] + d), x);
                // cout << "update " << grp[v] << " " << max(1, pos[v] - d) << " " << min(lim[grp[v]], pos[v] + d) << " : " << x << endl;
                if(pos[v] - d < 1) {
                    if(d - pos[v]) {
                        tree[grp[v]].update(1, 1, ri, 1, min(lim[grp[v]], d - pos[v]), -1 * x);
                        // cout << "update " << grp[v] << " " << 1 << " " << min(lim[grp[v]], d - pos[v]) << " : " << -1 * x << endl;
                    }
                    ri = lim[1];
                    tree[1].update(1, 1, ri, 1, min(d - pos[v] + 1, lim[1]), x);
                    // cout << "update " << 1 << " " << 1 << " " << min(d - pos[v] + 1, lim[1]) << " : " << x << endl;
                }
            }
        }
        else {
            int v;
            cin >> v;
            LL ans = 0;
            if(v != 1) {
                int ri = lim[1];
                ans += tree[1].query(1, 1, ri, pos[v] + 1, pos[v] + 1);
                ri = lim[grp[v]];
                ans += tree[grp[v]].query(1, 1, ri, pos[v], pos[v]);
            }
            else {
                int ri = lim[1];
                ans += tree[1].query(1, 1, ri, pos[v], pos[v]);
            }
            cout << ans << endl;
        }
        // cout << "qq : " << i << endl;
    }
    return 0;
}
/**
tags: segment tree, lazy propogation, lazy propogation with increment
*/