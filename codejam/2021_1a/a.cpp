#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 998244353
#define MX 300010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;
// int ara[110];
string str[110];
string orig[110];
int ans;

void func(int id1, int id2, int stat, int pos) {
    /*
    stat = 1; id2 is less
    stat = 2; id2 is more
    so far
    */

   if(id1 < str[pos - 1].size() && id2 < str[pos].size()) {
       if(stat) {
           func(id1 + 1, id2 + 1, stat, pos);
           return;
       }
       if(str[pos][id2] < str[pos - 1][id1]) {
           func(id1 + 1, id2 + 1, 1, pos);
       }
       if(str[pos][id2] > str[pos - 1][id1]) {
           func(id1 + 1, id2 + 1, 2, pos);
       }
       if(str[pos][id2] == str[pos - 1][id1]) {
           func(id1 + 1, id2 + 1, 0, pos);
       }
       return;
   }
   if(id1 < str[pos - 1].size() && id2 == str[pos].size()) {
       if(stat == 2) {
           /// some position was big
           str[pos] += '0';
           ans++;
           func(id1 + 1, id2 + 1, stat, pos);
        //    str[pos] += str[pos - 1][id1];
       }
       if(stat == 0) {
           /// all same
        //    if(str[pos - 1][id1] != '9') {
        //        str[pos] += (char)(str[pos - 1][id1] + 1);
        //        ans++;
        //        func(id1 + 1, id2 + 1, 2, pos);
        //    }
        //    else {
        //        str[pos] += str[pos - 1][id1];
        //        ans++;
        //        func(id1 + 1, id2 + 1, stat, pos);
        //    }
            str[pos] += str[pos - 1][id1];
            ans++;
            func(id1 + 1, id2 + 1, stat, pos);
       }
       if(stat == 1) {
           /// some position was less
            str[pos] += '0';
            ans++;
            func(id1 + 1, id2 + 1, stat, pos);
       }
       return;
   }
   if(id1 == str[pos - 1].size() && id2 == str[pos].size()) {
       if(stat == 0) {
           for(int x1 = str[pos].size() - 1; x1 >= orig[pos].size(); x1--) {
               if(str[pos][x1] < '9') {
                   str[pos][x1] = (char)(str[pos][x1] + 1);
                   for(int x2 = x1 + 1; x2 < str[pos].size(); x2++) {
                       str[pos][x2] = '0';
                   }
                   return;
               }
           }

           string tmp = orig[pos];
           for(int x1 = orig[pos].size(); x1 < str[pos - 1].size(); x1++) {
               tmp += '0';
           }
           str[pos] = tmp;
       }
       if(stat <= 1) {
            str[pos] += '0';
            ans++;
       }
   }

}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n;
        FOR(i, 1, n) {
            int tmp;
            cin >> tmp;
            str[i] = to_string(tmp);
            // cin >> str[i];
            orig[i] = str[i];
        }
        ans = 0;
        // int res = 0;
        FOR(i, 2, n) {
            
            
            if(str[i].size() > str[i - 1].size()) {
                continue;
            }
            func(0, 0, 0, i);
            // cout << i << " : " << str[i] << endl;
        }
        cout << "Case #" << tt << ": ";
        cout << ans << "\n";
    }
    return 0;
}
/**
 * 999999999
 * 100000000
 * 1000000000
 * 1100000000
 * 1991000000
*/
