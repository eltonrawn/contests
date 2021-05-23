#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int x;
int w, e;

map<int, int> beats, ulta_beats;
bool vis[65][65][65];
long double dp[65][65][65];

long double func(int cntR, int cntS, int cntP) {
    if(vis[cntR][cntS][cntP]) {
        return dp[cntR][cntS][cntP];
    }
    // cout << cntR << " " << cntS << " " << cntP << endl;
    if(cntR + cntS + cntP >= 60) {
        return dp[cntR][cntS][cntP] = 0;
    }

    vector<int> vv = {cntR, cntS, cntP};
    int mx = 0;
    for(int val: vv) mx = max(mx, val);

    long double ans = 0;

    for(int i = 0; i < 3; i++) {
        vector<int> soso; for(int val: vv) {soso.push_back(val);}
        soso[i]++;
        long double rr = 0;
        for(int j = 0; j < 3; j++) {
            if(j == i) {
                if(cntR + cntS + cntP)
                    rr += (long double)vv[beats[j]] / (long double)(cntR + cntS + cntP) * (long double)e;
            }
            if(beats[i] == j) {
                if(cntR + cntS + cntP)
                    rr += (long double)vv[beats[j]] / (long double)(cntR + cntS + cntP) * (long double)w;
            }
        }
        ans = max(ans,  rr + func(soso[0], soso[1], soso[2]));
    }
    vis[cntR][cntS][cntP] = 1;
    return dp[cntR][cntS][cntP] = ans;
}


string bt(int cntR, int cntS, int cntP) {
    if(cntR + cntS + cntP > 60) {
        return "";
    }

    vector<int> vv = {cntR, cntS, cntP};
    int mx = 0;
    for(int val: vv) mx = max(mx, val);


    long double ans = 0;

    for(int i = 0; i < 3; i++) {
        vector<int> soso; for(int val: vv) {soso.push_back(val);}
        soso[i]++;
        long double rr = 0;
        for(int j = 0; j < 3; j++) {
            if(j == i) {
                if(cntR + cntS + cntP)
                    rr += (long double)vv[beats[j]] / (long double)(cntR + cntS + cntP) * (long double)e;
            }
            if(beats[i] == j) {
                if(cntR + cntS + cntP)
                    rr += (long double)vv[beats[j]] / (long double)(cntR + cntS + cntP) * (long double)w;
            }
        }
        // ans = max(ans,  rr + func(soso[0], soso[1], soso[2]));
        if(rr + func(soso[0], soso[1], soso[2]) == dp[cntR][cntS][cntP]) {
            string tmp;
            if(i == 0) tmp = "R";
            if(i == 1) tmp = "P";
            if(i == 2) tmp = "S";
            tmp += bt(soso[0], soso[1], soso[2]);
            return tmp;
        }
    }
    return "";
}

int main() {
   freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    beats[0] = 2;
    beats[1] = 0;
    beats[2] = 1;

    ulta_beats[2] = 0;
    ulta_beats[0] = 1;
    ulta_beats[1] = 2;

    int tc;
    cin >> tc;
    cin >> x;
    for(int tt = 1; tt <= tc; tt++) {
        memset(vis, 0, sizeof(vis));
        cin >> w >> e;
        cout << "Case #" << tt << ": ";
        // cout << func(0, 0, 0) << endl;
        func(0, 0, 0);
        cout << bt(0, 0, 0) << endl;
        // cout << "make : " << make << endl;
    }
    return 0;
}
/**
*/
