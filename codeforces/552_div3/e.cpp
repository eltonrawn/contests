#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
int skill[SZ];
set<int> peeps;
set< PII > skill_pr;
int ans[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> skill[i];
        peeps.insert(i);
        skill_pr.insert({skill[i], i});
    }

    int turn = 1;
    while(!peeps.empty()) {
        auto it2 = skill_pr.end(); it2--;
        PII top = *it2;

        auto it = peeps.find(top.second);
        
        int cnt = 0;
        vector<int> rm;
        while(cnt < k) {
            if(it == peeps.begin()) {
                break;
            }
            it--;
            cnt++;
            rm.push_back(*it);
        }

        it = peeps.find(top.second);
        cnt = 0;

        while(cnt < k) {
            it++;
            if(it == peeps.end()) {
                break;
            }
            cnt++;
            rm.push_back(*it);
        }
        rm.push_back(top.second);

        for(int pos: rm) {
            peeps.erase(pos);
            skill_pr.erase({skill[pos], pos});
            ans[pos] = turn;
        }

        if(turn == 1) turn = 2;
        else turn = 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;

    
    return 0;
}
/**
start: 2:48 am
end: 3:11 am
duration: 23 mins
comment: it should have been done in 10 mins. extra time taken was due to stupid bugs and debugging.
*/
