#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, m;
string orig[SZ], changed[SZ];
int freq_orig[26], freq_changed[26];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> orig[i];
        }
        for(int i = 0; i < n - 1; i++) {
            cin >> changed[i];
        }
        set<int> process_orig;//, process_changed;
        for(int i = 0; i < n; i++) {
            process_orig.insert(i);
        }
        // for(int i = 0; i < n - 1; i++) {
        //     process_changed.insert(i);
        // }

        for(int j = 0; j < m; j++) {
            // for(int k = 0; k < 26; k++) {
            //     freq[k].clear();
            // }
            for(int k = 0; k < 26; k++) {
                freq_orig[k] = 0;
                freq_changed[k] = 0;
            }
            // for(int i: process_orig) {
            //     freq_orig[orig[i][j] - 'a']++;
            // }
            // for(int i: process_changed) {
            //     freq_changed[changed[i][j] - 'a']++;
            // }

            for(int i = 0; i < n; i++) {
                freq_orig[orig[i][j] - 'a']++;
            }
            for(int i = 0; i < n - 1; i++) {
                freq_changed[changed[i][j] - 'a']++;
            }

            int nono;
            for(int k = 0; k < 26; k++) {
                if(freq_orig[k] != freq_changed[k])
                    nono = k;
            }

            vector<int> rr;
            for(int i: process_orig) {
                if(orig[i][j] - 'a' != nono) {
                    rr.push_back(i);
                }
            }
            for(int val: rr) process_orig.erase(val);

            // rr.clear();
            // for(int i: process_changed) {
            //     if(changed[i][j] - 'a' != nono) {
            //         rr.push_back(i);
            //     }
            // }
            // for(int val: rr) process_changed.erase(val);

        }
        cout << orig[*process_orig.begin()] << endl;
    }
    return 0;
}
/**
abcdef
uuuuuu
kekeke
ekekek
xyzklm

xbcklf
eueueu
ayzdem
ukukuk
*/
