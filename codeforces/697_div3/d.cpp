#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
vector<int> a;
vector<int> b;

vector<int> cost1, cost2;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        a.clear(); b.clear(); cost1.clear(); cost2.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int tmp;cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0; i < n; i++) {
            int tmp;cin >> tmp;
            b.push_back(tmp);
            if(tmp == 1)
                cost1.push_back(a[i]);
            else
                cost2.push_back(a[i]);
        }
        sort(cost1.begin(), cost1.end());
        sort(cost2.begin(), cost2.end());
        LL taken = 0;
        LL cost = 0;
        while(taken < m && !cost1.empty() && !cost2.empty()) {
            if(cost1.back() + taken >= m || cost1.back() > cost2.back()) {
                cost += 1;
                taken += cost1.back();
                cost1.pop_back();
                continue;;
            }
            if(cost1.size() >= 2 && (cost1.back() + cost1[cost1.size() - 2]) > cost2.back()) {
                cost += 1;
                taken += cost1.back();
                cost1.pop_back();
                continue;
            }
            cost += 2;
            taken += cost2.back();
            cost2.pop_back();
        }
        while(taken < m && !cost1.empty()) {
            cost += 1;
            taken += cost1.back();
            cost1.pop_back();
        }
        while(taken < m && !cost2.empty()) {
            cost += 2;
            taken += cost2.back();
            cost2.pop_back();
        }
        if(taken < m) {
            cout << -1 << endl;
            continue;
        }
        cout << cost << endl;
    }
    return 0;
}
/**
*/
