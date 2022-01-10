#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int init = 0;
int n;

void ask_for_ans(int c) {
    init += c;
    cout << "+ " << c << endl;
}

int get_ans() {
    // return init / n;
    int tmp; cin >> tmp;
    return tmp;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    // cin >> init;
    int orig_le = 0, orig_ri = n - 1;
    int cur_le = 0, cur_ri = n - 1;
    int last_ans = 0;
    while(cur_le < cur_ri) {
        int mid = cur_le + (cur_ri - cur_le) / 2;
        
        /// first half -> cur_le to mid
        /// second half -> mid + 1 to cur_ri
        
        int c = n - 1 - mid;
        // cout << "mid : " << mid << endl;
        // cout << "c : " << c << endl;
        ask_for_ans(c);
        int cur_ans = get_ans();
        if(cur_ans == last_ans) {
            /// first half is ans
            orig_ri = orig_le + (mid - cur_le);
            cur_ri = mid;
        }
        else {
            /// last half is ans
            orig_le = orig_ri - (cur_ri - (mid + 1));
            cur_le = mid + 1;
        }
        cur_le += c;
        cur_ri += c;
        cur_le %= n;
        cur_ri %= n;
        last_ans = cur_ans;
        // cout << "cur " << cur_ans << " " << cur_le << " " << cur_ri << endl;
    }
    cout << "! " << orig_le + init << endl;

    return 0;
}
/**
coding start: 9:02 pm
*/
