#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class Cmp {
public:
    bool operator()(PII a, PII b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

};

LL n, x, y;
PII ara[SZ];
multiset<PII, Cmp> st1, st2;

LL get_cost_m(LL le, LL ri) {
    return (x + y * (ri - le)) % MOD;
}

LL get_cost(LL le, LL ri) {
    return (x + y * (ri - le));
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i].first >> ara[i].second;
    }
    sort(ara + 1, ara + n + 1);
    LL ans = 0;
    for(int i = 1; i <= n; i++) {
        while(!st2.empty()) {
            auto it = st2.end(); it--;
            PII top = *it;
            if(top.second >= ara[i].first) {
                break;
            }
            st2.erase(it);
            st1.insert(top);
        }
        // cout << i << endl;
        if(st1.empty()) {
            st2.insert(ara[i]);
            ans += get_cost_m(ara[i].first, ara[i].second);
            if(ans >= MOD) ans -= MOD;
            // cout << "1 " << ara[i].first << " " << ara[i].second << endl;
            continue;
        }
        auto it = st1.begin();
        PII top = *it;
        
        if(get_cost(top.first, ara[i].second) < get_cost(top.first, top.second) + get_cost(ara[i].first, ara[i].second)) {
            /// using same is cheaper
            st1.erase(it);
            ans -= get_cost_m(top.first, top.second);
            ans = (ans % MOD + MOD) % MOD;
            st2.insert({top.first, ara[i].second});
            ans += get_cost_m(top.first, ara[i].second);
            if(ans >= MOD) ans -= MOD;
            // cout << "2 " << top.first << " " << ara[i].second << endl;
        }
        else {
            /// buy new one
            st2.insert({ara[i].first, ara[i].second});
            ans += get_cost_m(ara[i].first, ara[i].second);
            if(ans >= MOD) ans -= MOD;
            // cout << "3 " << ara[i].first << " " << ara[i].second << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
/**
start: 11:34 pm
end: 12:13 am
duration: 40 mins
*/
