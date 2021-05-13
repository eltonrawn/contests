#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;



int n;
int ara[SZ];
int mylog[SZ];
int st[SZ][40];

void init_sparse() {
    mylog[1] = 0;
    for (int i = 2; i <= n; i++)
        mylog[i] = mylog[i/2] + 1;
    
    for (int i = 0; i < n; i++)
        st[i][0] = ara[i];

    for (int j = 1; j <= 25; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
            
        }
    }

}

int get_min(int l, int r) {
    int j = mylog[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int prefix_mx[SZ];
int suffix_mx[SZ];


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        init_sparse();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, ara[i]);
            prefix_mx[i] = mx;
        }

        mx = 0;
        for(int i = n - 1; i >= 0; i--) {
            mx = max(mx, ara[i]);
            suffix_mx[i] = mx;
        }
        pair<int, PII> ans = {-1, {-1, -1}};
        for(int i = 0; i < n - 2; i++) {
            int val = prefix_mx[i];
            int lo = i + 1, hi = n - 2;
            while(lo < hi) {
                int mid = lo + ((hi - lo + 1) / 2);
                if(get_min(i + 1, mid) < val) {
                    hi = mid - 1;
                }
                else {
                    lo = mid;
                }
            }
            // cout << i << " : " << lo << endl;
            if(get_min(i + 1, lo) != val) continue;
            if(suffix_mx[lo + 1] == val) {
                /// 1 to i, i + 1 to lo, lo + 1 to n - 1
                ans = {i + 1, {lo - i, n - 1 - lo}};
                break;
            }
            lo--;
            if(lo < i + 1) continue;
            if(get_min(i + 1, lo) != val) continue;
            if(suffix_mx[lo + 1] == val) {
                /// 1 to i, i + 1 to lo, lo + 1 to n - 1
                ans = {i + 1, {lo - i, n - 1 - lo}};
                break;
            }
        }
        if(ans.first == -1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << ans.first << " " << ans.second.first << " " << ans.second.second << endl;


    }
    return 0;
}
/**
*/
