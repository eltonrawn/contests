#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

double get_dis(PII fir, PII sec) {
    double a = (fir.first - sec.first) * (fir.first - sec.first);
    double b = (fir.second - sec.second) * (fir.second - sec.second);
    return sqrt(a + b);
}

double get_prob(double d, double r) {
    return exp(1 - ((d * d) / (r * r)));
}

int n;
int k, eps;
PII sxy;
PII xy[SZ];
double rad;
bool vis[110][110];
double dp[110][110];

double func(int pos, int taken) {
    // returns the probability of not completing the task
    if(pos > n) {
        if(taken >= k) return 0;
        return 1;
    }
    if(vis[pos][taken]) return dp[pos][taken];
    double tmp = 0;
    double d = get_dis(sxy, xy[pos]);
    double prob = get_prob(d, rad);
    if(d <= rad) {
        tmp += 1.0 * func(pos + 1, taken + 1);
    }
    else {
        // taking
        tmp += prob * func(pos + 1, taken + 1);
        // not taking
        tmp += (1.0 - prob) * func(pos + 1, taken);
    }
    // cout << pos << " " << taken << " : " << d << " " << prob << " " << tmp << endl;
    vis[pos][taken] = 1;
    return dp[pos][taken] = tmp;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> k >> eps;
    cin >> sxy.first >> sxy.second;
    double mx_dis = 0;
    for(int i = 1; i <= n; i++) {
        cin >> xy[i].first >> xy[i].second;
        mx_dis = max(mx_dis, get_dis(sxy, xy[i]));
    }
    // rad = 3.84257761518762740;
    // rad = 3.83;
    // // rad = 3.0;
    // double loss_prob = func(1, 0);
    // cout << loss_prob << " " << (loss_prob * 1000 <= eps) << endl;
    double lo = 0, hi = mx_dis;
    for(int i = 1; i <= 100; i++) {
        double mid = lo + (hi - lo) / 2;
        rad = mid;
        memset(vis, 0, sizeof(vis));
        if(func(1, 0) * 1000 <= eps) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(17) << lo << endl;
    return 0;
}
/**
tags: dp with probability, repeat, 2100, probability
*/
