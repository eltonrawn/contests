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

int n, m;
int a[2000][2000];
int b[2000][2000];
map<string, int> ss;
vector<int> pps[2000];

// bool taken_col[2000];
int ord[2000], sa[2000];
int st[2000];

vector<int> mis[2000][2000];
int mis_cnt[2000];


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> m;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> b[i][j];
        }
    }

    int cnt = 1;
    ROF(i, n, 1) {
        string str = "";
        FOR(j, 1, m) {
            str += "_" + to_string(b[i][j]);
        }
        int pos = ss[str];
        if(pos == 0) {
            pos = cnt;
            ss[str] = pos;
            cnt++;
        }
        pps[pos].PB(i);
    }

    FOR(i, 1, n) {
        string str = "";
        FOR(j, 1, m) {
            str += "_" + to_string(a[i][j]);
        }
        int pos = ss[str];
        if(pos == 0 || pps[pos].empty()) {
            cout << -1 << endl;
            return 0;
        }
        ord[ i ] = pps[pos].back();
        pps[pos].pop_back();
    }

    FOR(i, 1, n) {
        sa[ ord[i] ] = i;
    }

    // FOR(i, 1, n) {
    //     cout << sa[i] << " : ";
    //     FOR(j, 1, m) {
    //         cout << a[ sa[i] ][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> ans;
    st[ sa[1] ] = 1;
    // cout << "mark st : " << sa[1] << " " << 1 << endl;
    /// order of a, corresponding to b is done

    queue<int> q;

    FOR(j, 1, m) {
        bool chk = 1;
        FOR(pp, 2, n) {
            int back = sa[pp - 1];
            int cur = sa[pp];
            if(a[back][j] > a[cur][j]) {
                /// not possible
                chk = 0;
                mis[cur][back].PB(j);
                mis_cnt[j]++;
            }
        }
        if(chk == 0) {
            continue;
        }
        
        // cout << "col taken : " << j << endl;
        
        q.push(j);
    }

    while(!q.empty()) {
        int j = q.front();
        ans.PB(j);
        q.pop();
        FOR(pp, 2, n) {
            if(st[ sa[pp] ]) {
                continue;
            }
            int back = sa[pp - 1];
            int cur = sa[pp];
            if(a[back][j] < a[cur][j]) {
                st[ sa[pp] ] = 1;
                for(int col: mis[cur][back]) {
                    mis_cnt[col]--;
                    if(mis_cnt[col] == 0) {
                        q.push(col);
                    }
                }
                // cout << "mark st : " << sa[pp] << " " << pp << endl;
            }
        }
    }
    
    FOR(col, 1, m) {
        if(mis_cnt[col]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";;
    for(int val: ans) {
        cout << val << " ";
    }
    cout << "\n";


    return 0;
}
/**
*/
