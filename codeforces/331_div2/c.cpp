#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


struct Data  {
    LL sum, mx;
    Data()  {
        sum = 0;
        mx = -1;
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
        left_v.mx = max(left_v.mx, right_v.mx);
        return left_v;
    }
    
    void update(int ll, int rr, int pos, int t_pos, LL t_val)    {
        if(t_pos < ll || t_pos > rr) {
            return;
        }
        if((ll == rr) && (rr == t_pos))   {
            tree[pos].mx = t_val;
            tree[pos].sum = t_val;
            return;
        }
        int mid = (ll + rr) / 2;

        update(ll, mid, pos * 2, t_pos, t_val);
        update(mid + 1, rr, (pos * 2) + 1, t_pos, t_val);

        tree[pos].sum = tree[pos * 2].sum + tree[(pos * 2) + 1].sum;
        tree[pos].mx = max(tree[pos * 2].mx, tree[(pos * 2) + 1].mx);
    }

};


int n;
PII points[SZ];
int ara[SZ];

map< int, vector<int> > aramp;
map< int, vector<PII> > pointsmp;

PII fin_points[SZ];

Segtree on_x = Segtree(); /// gives y
Segtree on_y = Segtree(); /// gives x

bool valid() {
    for(int i = 1; i <= n; i++) {
        int x = fin_points[i].first;
        int y = fin_points[i].second;
        if(on_x.query(1, n, 1, x, SZ - 1).mx >= y) {
            return 0;
        }
        if(on_y.query(1, n, 1, y, SZ - 1).mx >= x) {
            return 0;
        }
        
        if(on_x.query(1, n, 1, x, x).mx == -1)
            on_x.update(1, n, 1, x, y);

        if(on_y.query(1, n, 1, y, y).mx == -1)
            on_y.update(1, n, 1, y, x);
    }
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
        points[i].first++;
        points[i].second++;
        pointsmp[points[i].second - points[i].first].push_back(points[i]);
    }

    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        aramp[ara[i]].push_back(i);
    }

    // for(auto it: aramp) {
    //     cout << it.first << " : ";
    //     for(int val: it.second) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    bool chk = 1;
    for(auto it: aramp) {
        if(it.second.size() != pointsmp[it.first].size()) {
            chk = 0; break;
        }
        sort(pointsmp[it.first].begin(), pointsmp[it.first].end());
        for(int i = 0; i < it.second.size(); i++) {
            fin_points[it.second[i]] = pointsmp[it.first][i];
        }
    }
    if(!chk || !valid()) {
        cout << "NO" << endl; return 0;
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << fin_points[i].first - 1 << " " << fin_points[i].second - 1 << endl;
    }
    return 0;
}
/**
start: 10:25 pm
end: 11:07 pm
duration: 42 mins
*/
