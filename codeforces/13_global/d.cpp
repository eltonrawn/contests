#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

// from u to v
int u, v;

// bool func(int pos, int taken, bool v_taken) {
//     // cout << pos << " " << taken << endl;
//     if(pos < 0) {
//         if(taken) return 0;
//         return 1;
//     }
//     int tmp = taken;
//     if(v & (1 << pos)) {
//         tmp++;
//         v_taken = 1;
//     }
//     if(u & (1 << pos)) {
//         if(!v_taken) return 0;
//         if(taken)
//             return func(pos - 1, tmp - 1, v_taken);
//         if(tmp > taken) {
//             /// v and u both bit on
//             return func(pos - 1, taken, v_taken);
//         }

//         if(!taken)
//             return 0;
        
//     }
//     else {
//         return func(pos - 1, tmp, v_taken);
//     }
// }

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> u >> v;
        int start = 30;
        bool chk = 1;
        for(int i = 30; i >= 0; i--) {
            if(v & (1 << i)) {
                start = i;
                break;
            }
            if(u & (1 << i)) {
                chk = 0;
                break;
            }
        }
        bool v_oid = 0;
        int v_baki = 0;
        for(int i = start; i >= 0; ) {
            
            int j = i - 1;
            while(j >= 0 && (v & (1 << j)) == 0) {
                j--;
            }

            int u_taken = 0;
            for(int k = i; k > j; k--) {
                if(u & (1 << k)) {
                    u_taken++;
                }
            }

            if(u_taken >= 2 && (u & (1 << i)) && !v_oid) {
                // cout << "hi" << endl;
                chk = 0;break;
            }

            if((u & (1 << i)) == 0)
                v_oid = 1;

            v_baki++;
            for(int k = i; k > j; k--) {
                if(u & (1 << k) && v_baki) {
                    v_baki--;
                }
            }

            // if(v_baki) v_oid = 1;
            i = j;
        }
        
        if(v_baki)
            chk = 0;

        cout << (chk == 0? "NO" : "YES") << endl;
        // cout << (func(30, 0, 0) == 0? "NO" : "YES") << endl;
    }
    return 0;
}
/**
*/
