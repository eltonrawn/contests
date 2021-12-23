#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
class Data {
public:
    string str;
    int no_s;
    int no_h;
};

LL get_ans(string str) {
    LL no_h = 0;
    LL ans = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        if(str[i] == 'h') {
            no_h++;
            continue;
        }
        ans += no_h;
    }
    return ans;
}


Data datas[SZ];

class Cmp {
public:
    bool operator()(Data a, Data b) {
        // if(a.no_h == b.no_h) {
        //     return a.no_s > b.no_s;
        // }
        // return a.no_h < b.no_h;
        return get_ans(a.str + b.str) > get_ans(b.str + a.str);
    }
};

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> datas[i].str;
        for(int j = 0; j < datas[i].str.size(); j++) {
            if(datas[i].str[j] == 's') datas[i].no_s++;
            else datas[i].no_h++;
        }
        
    }
    sort(datas + 1, datas + n + 1, Cmp());
    string str = "";
    for(int i = 1; i <= n; i++) {
        str += datas[i].str;
    }
    
    cout << get_ans(str) << endl;
    return 0;
}
/**
start: 3:31 am
end: 4:03 am
duration: 32 mins; idea was wrong. so no regret as an observation is needed.
*/
