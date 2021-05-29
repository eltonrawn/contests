#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


struct Data  {
    LL sum;
    Data()  {
        sum = 0;
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

        left_v.sum += right_v.sum;
        return left_v;
    }
    
    void update(int ll, int rr, int pos, int t_pos, LL t_val)    {
        if(t_pos < ll || t_pos > rr) {
            return;
        }
        if((ll == rr) && (rr == t_pos))   {
            tree[pos].sum = t_val;
            return;
        }
        int mid = (ll + rr) / 2;

        update(ll, mid, pos * 2, t_pos, t_val);
        update(mid + 1, rr, (pos * 2) + 1, t_pos, t_val);

        tree[pos].sum = tree[pos * 2].sum + tree[(pos * 2) + 1].sum;
    }

};

class cmp {
public:
    bool operator()(PII a, PII b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int n;
int ara[SZ];
int ans = 0;
set<PII, cmp> st;

set<int> pp;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Segtree segtree = Segtree();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(ara[i] >= 0) {
            segtree.update(1, n, 1, i, ara[i]);
            ans++;
            if(ara[i] > 0) pp.insert(i);
        }
        if(ara[i] < 0) {
            st.insert({i, ara[i]});
        }
    }
    for(PII pr: st) {
        int pos = pr.first;
        int val = pr.second;
        int kk = val * -1;
        // cout << pos << " " << val << " : " << segtree.query(1, n, 1, 1, pos).sum << endl;
        if(segtree.query(1, n, 1, 1, pos).sum >= kk) {
            ans++;
            auto it = pp.upper_bound(pos);
            vector<int> er;
            while(it != pp.begin() && kk) {
                it--;
                int idx = *it;
                // cout << "idx : " << idx << endl;
                // int vv = ara[*it];
                int mn = min(kk, ara[idx]);
                ara[idx] -= mn;
                kk -= mn;
                // cout << mn << " ";
                segtree.update(1, n, 1, idx, ara[idx]);
                if(ara[idx] == 0)
                    er.push_back(idx);
            }
            for(int era: er)
                pp.erase(era);
            // cout << endl;
            // segtree.update(1, n, 1, pos, val);
        }
    }
    cout << ans << endl;

    return 0;
}
/**
*/
