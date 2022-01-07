#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int inf = 1000000000;
int n, s, l;
int ara[SZ];
vector<int> sor_ara;
map<int, int> ara_mp;

struct Data  {
    int mn;
    Data()  {
        mn = inf;
    }
};

class Segtree {
public:
    Data tree[SZ * 4];
    
    Data query(int ll, int rr, int pos, int t_l, int t_r) {  //t_l = target left
        if((ll >= t_l) && (rr <= t_r))  {
            return tree[pos];
        }
        
        if((ll > t_r) || (rr < t_l))   {
            return Data();
        }

        int mid = (ll + rr) / 2;
        Data left_v = query(ll, mid, pos * 2, t_l, t_r);
        Data right_v = query(mid + 1, rr, (pos * 2) + 1, t_l, t_r);

        left_v.mn = min(left_v.mn, right_v.mn);
        return left_v;
    }
    
    void update(int ll, int rr, int pos, int t_pos, int t_val)    {
        if(t_pos < ll || t_pos > rr) {
            return;
        }
        if((ll == rr) && (rr == t_pos))   {
            tree[pos].mn = t_val;
            return;
        }
        int mid = (ll + rr) / 2;

        update(ll, mid, pos * 2, t_pos, t_val);
        update(mid + 1, rr, (pos * 2) + 1, t_pos, t_val);

        tree[pos].mn = min(tree[pos * 2].mn, tree[(pos * 2) + 1].mn);
    }
};

Segtree for_gr_tree = Segtree();
Segtree for_ls_tree = Segtree();
Segtree dp = Segtree();

int get_next_for_gr_pos(int val) {
    int pp = upper_bound(sor_ara.begin(), sor_ara.end(), val + s) - sor_ara.begin();
    if(pp >= sor_ara.size()) return inf;
    int nxt_for_val = sor_ara[pp];
    return for_gr_tree.query(1, n, 1, ara_mp[nxt_for_val], n).mn;
}


int get_next_for_ls_pos(int val) {
    int pp = lower_bound(sor_ara.begin(), sor_ara.end(), val - s) - sor_ara.begin();
    if(pp == 0) return inf;
    pp--;
    int nxt_for_val = sor_ara[pp];
    return for_ls_tree.query(1, n, 1, 1, ara_mp[nxt_for_val]).mn;   
}

void update_for_pos(int pos) {
    for_gr_tree.update(1, n, 1, ara_mp[ara[pos]], pos);
    for_ls_tree.update(1, n, 1, ara_mp[ara[pos]], pos);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s >> l;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        sor_ara.push_back(ara[i]);
    }
    sort(sor_ara.begin(), sor_ara.end());
    sor_ara.erase(unique(sor_ara.begin(), sor_ara.end()), sor_ara.end());

    for(int i = 0; i < sor_ara.size(); i++) {
        ara_mp[sor_ara[i]] = i + 1;
    }

    int till = n + 1;
    dp.update(1, n, 1, n, 0);
    /// dp[i] contains ans from i + 1 to end
    for(int i = n; i >= 1; i--) {
        till = min(till, get_next_for_gr_pos(ara[i]));
        till = min(till, get_next_for_ls_pos(ara[i]));
        // cout << i << " till : " << till << endl;
        int val = inf;
        if(i + l - 1 <= till - 1)
            val = min(val, dp.query(1, n, 1, i + l - 1, till - 1).mn + 1);
        
        // cout << i << " -> " << i + l - 1 << " " << till - 1 << " : " << val << endl;
        if(i == 1) {
            if(val <= n) {
                cout << val << endl;
                return 0;
            }
            break;
        }
        update_for_pos(i);
        dp.update(1, n, 1, i - 1, val);
    }
    cout << -1 << endl;

    return 0;
}
/**
start: 1:50 pm
coding start: 2:15 pm
end: 3:55 pm
duration: 2 hrs 5 mins. too slow. also, was stucked on a stupid mistake. though problem was interesting.
tags: repeat, segment tree, rmq
*/
