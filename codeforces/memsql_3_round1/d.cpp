#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 70
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
double win_prob[SZ][SZ], total_prob[SZ][SZ], ev[SZ][SZ];
vector<int> competitor_vec[SZ][SZ];
int no_teams;

double calculate_ev() {
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        // i is round
        for(int u = 1; u <= no_teams; u++) {
            // u is winning teams
            double tmp_ev = 0;
            for(int v: competitor_vec[i][u]) {
                tmp_ev = max(tmp_ev, ev[i - 1][v]);
            }
            ev[i][u] = tmp_ev + ev[i - 1][u] + (total_prob[i][u] * (1 << (i - 1)));

            if(i == n) ans = max(ans, ev[i][u]);
        }
    }
    return ans;
}

void calculate_prob() {
    for(int u = 1; u <= no_teams; u++) {
        total_prob[0][u] = 1;
    }
    for(int i = 1; i <= n; i++) {
        // i is round
        for(int u = 1; u <= no_teams; u++) {
            double tmp_prob = 0;
            // u is winning teams
            for(int v: competitor_vec[i][u]) {
                tmp_prob += total_prob[i - 1][v] * win_prob[u][v];
            }
            total_prob[i][u] = total_prob[i - 1][u] * tmp_prob;
        }
    }
}

void calculate_competitor(int round, int le, int ri) {
    if(round == 0) {
        return;
    }
    
    int mid = (le + ri) / 2;

    for(int i = le; i <= mid; i++) {
        for(int j = mid + 1; j <= ri; j++) {
            competitor_vec[round][i].push_back(j);
        }
    }
    for(int i = mid + 1; i <= ri; i++) {
        for(int j = le; j <= mid; j++) {
            competitor_vec[round][i].push_back(j);
        }
    }
    calculate_competitor(round - 1, le, mid);
    calculate_competitor(round - 1, mid + 1, ri);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    no_teams = 1 << n;
    
    calculate_competitor(n, 1, no_teams);

    // for(int i = 1; i <= n; i++) {
    //     cout << "round " << i << " : " << endl;
    //     for(int j = 1; j <= no_teams; j++) {
    //         cout << "team " << j << " : ";
    //         for(int vv: competitor_vec[i][j]) {
    //             cout << vv << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    for(int i = 1; i <= no_teams; i++) {
        for(int j = 1; j <= no_teams; j++) {
            cin >> win_prob[i][j];
            win_prob[i][j] /= 100.0;
        }
    }

    calculate_prob();

    // for(int i = 1; i <= n; i++) {
    //     cout << "round " << i << " : " << endl;
    //     for(int j = 1; j <= no_teams; j++) {
    //         cout << j << " : " << total_prob[i][j] << endl;
    //     }
    // }

    cout << fixed << setprecision(15) << calculate_ev() << endl;

    return 0;
}
/**
start: 2:48 pm
coding start: 3:08 pm

tags: probability, expected value, dp with expected value, repeat, 2100
*/
