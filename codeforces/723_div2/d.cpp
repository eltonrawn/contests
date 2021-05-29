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
Segtree segtree = Segtree();


vector<int> vv[30];
string str;

LL func(string trans) {
    // cout << trans << endl;
    for(int i = 0; i < 26; i++) {
        vv[i].clear();
    }
    for(int i = 0; i < str.size(); i++) {
        segtree.update(1, str.size(), 1, i + 1, 1);
    }
    
    for(int i = trans.size() - 1; i >= 0; i--) {
        vv[trans[i] - 'A'].push_back(i + 1);
    }
    LL ans = 0;
    for(int i = 0; i < str.size(); i++) {
        int pp = vv[str[i] - 'A'].back();
        if(pp != 1)
            ans += segtree.query(1, str.size(), 1, 1, pp - 1).sum;
        segtree.update(1, str.size(), 1, pp, 0);
        vv[str[i] - 'A'].pop_back();
    }
    return ans;
}

map<char, int> mp;
string unq = "ANOT";

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // str = "OAANTTON";
    // cout << func("TNNTAOOA") << endl;
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> str;
        mp.clear();
        for(int i = 0; i < str.size(); i++) {
            mp[str[i]]++;
        }
        // string yoyo = str;
        // reverse(yoyo.begin(), yoyo.end());
        // cout << "rev : " << func(yoyo) << endl;
        sort(unq.begin(), unq.end());
        string ans;
        LL mx = -1;

        do {
            // cout << unq << endl;
            string ss;
            for(char val: unq) {
                for(int i = 1; i <= mp[val]; i++) {
                    ss += val;
                }
            }
            LL tmp = func(ss);
            // LL tmp = 0;
            if(tmp > mx) {
                mx = tmp;
                ans = ss;
            }

        } while (next_permutation(unq.begin(), unq.end()));
        // cout << mx << " ";
        cout << ans << endl;
    }
    return 0;
}
/**
*/
