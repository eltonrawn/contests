#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str, orig;
int freq[26];
vector<int> vv[26];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> str;
        orig = str;
        
        memset(freq, 0, sizeof(freq));
        sort(str.begin(), str.end());
        for(int i = 0; i < str.size(); i++) {
            freq[str[i] - 'a']++;
        }
        int mxshift = 0;
        for(int i = 0; i < 26; i++) {
            mxshift = max(mxshift, freq[i]);
            vv[i].clear();
        }

        // cout << str << endl;

        for(int i = 0; i < str.size(); i++) {
            vv[str[i] - 'a'].push_back(str[(i + mxshift) % str.size()] - 'a');
            // cout << str[i] << " " << str[(i + mxshift) % str.size()] << endl;
        }

        cout << "Case #" << tt << ": ";
        if(str.size() < 2 * mxshift) {cout << "IMPOSSIBLE" << endl; continue;}

        for(int i = 0; i < orig.size(); i++) {
            cout << (char)(vv[orig[i] - 'a'].back() + 'a');
            vv[orig[i] - 'a'].pop_back();
        }
        cout << endl;

    }
    return 0;
}
/**
*/
