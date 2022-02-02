#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 2010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int n;
int adjm[SZ][SZ];
int vis[SZ];
vector<PII> edges;

void ask_question(int u) {
    cout << "? " << u << endl;
    for(int v = 1; v <= n; v++) {
        int dis; cin >> dis;
        adjm[u][v] = dis;
        adjm[v][u] = dis;
    }
}

// void func(int u, int par, bool ask) {
//     if(u != 1)
//         edges.push_back({u, par});
//     // cout << u << " " << par << " " << ask << endl;
    
//     vector<int> vv;
//     if(ask) {
//         ask_question(u);
        
        
//         for(int v = 1; v <= n; v++) {
//             if(vis[v]) continue;
//             if(adjm[u][v] == 1) {
//                 vis[v] = 1;
//                 vv.push_back(v);
//             }
//         }
//         // edges.push_back({u, vv.back()});
//     }
//     else {
//         for(int v = 1; v <= n; v++) {
//             if(vis[v]) continue;
//             if(adjm[par][v] == 2) {
//                 vis[v] = 1;
//                 vv.push_back(v);
//             }
//         }
//     }

//     for(int v: vv) {
//         if(v == vv.back()) continue;
//         func(v, u, 1);
//     }

//     if(vv.size() == 0) return;
//     if(ask == 0 && vv.size() == 1)
//         func(vv.back(), u, 1);
//     else
//         func(vv.back(), u, 0);

//     // if(vv.size() == 1) {
        
//     //     return;
//     // }

//     // vector<int> yo;
//     // for(int v = 1; v <= n; v++) {
//     //     if(vis[v]) continue;
//     //     int cnt = 0;
//     //     for(int foo: vv) {
//     //         if(foo == vv.back()) break;
//     //         if(adjm[foo][v] == 3) {
//     //             cnt++;
//     //         }
//     //     }
//     //     if(cnt == vv.size() - 1) {
//     //         yo.push_back(v);
//     //     }
//     // }
//     // for(int v: yo) {
//     //     func(v, vv.back());
//     // }

// }

int dis_parity[2];
vector<int> initial_dis[SZ];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    ask_question(1);
    int mx_lev = 0;
    for(int v = 1; v <= n; v++) {
        initial_dis[adjm[1][v]].push_back(v);
        mx_lev = max(mx_lev, adjm[1][v]);
        dis_parity[adjm[1][v] % 2]++;
    }
    bool is_even = 0;
    if(dis_parity[0] <= dis_parity[1]) {
        /// ask questions for whose distance is even
        is_even = 1;
    }

    for(int v = 1; v <= mx_lev; v++) {
        if((v % 2 == 0 && is_even) || (v % 2 && !is_even)) {
            for(int val: initial_dis[v]) {
                ask_question(val);
            }
        }
        for(int u1: initial_dis[v - 1]) {
            for(int u2: initial_dis[v]) {
                if(adjm[u1][u2] == 1) {
                    edges.push_back({u1, u2});
                }
            }
        }
    }

    // cin >> n;
    // vis[1] = 1;
    // func(1, 0, 1);

    cout << "!" << endl;
    for(PII val: edges)
        cout << val.first << " " << val.second << endl;
    return 0;
}
/**
*/
