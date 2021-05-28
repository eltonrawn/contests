#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

string str;
map<char, char> ulta_beats;
map<char, int> freq;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ulta_beats['P'] = 'S';
    ulta_beats['S'] = 'R';
    ulta_beats['R'] = 'P';
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        freq.clear();
        cin >> str;
        int mx = 0;
        char mxch;
        for(int i = 0; i < str.size(); i++) {
            freq[str[i]]++;
            if(freq[str[i]] > mx) {
                mx = freq[str[i]];
                mxch = str[i];
            }
        }
        char ans = ulta_beats[mxch];
        for(int i = 0; i < str.size(); i++) {
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}
/**
*/
