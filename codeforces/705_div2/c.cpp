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
#define MX 100010
#define INFL 1000000000000000000LL
#define INF 1000000000

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, k;
string str;
int freq[MX][26];

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc) {
        cin >> n >> k >> str;
        if(n % k) {
            cout << -1 << "\n";
            continue;
        }

        FOR(i, 0, n - 1) {
            FOR(j, 0, 25) {
                freq[i][j] = 0;
            }
        }

        FOR(i, 0, n - 1) {
            if(i != 0) {
                FOR(j, 0, 25) {
                    freq[i][j] = freq[i - 1][j];
                }
            }

            freq[i][ str[i] - 'a' ]++;
        }

        bool yoyo = 1;
        FOR(j, 0, 25) {
            if(freq[n - 1][j] % k) {
                yoyo = 0;
                break;
            }
        }
        if(yoyo) {
            cout << str << "\n";
            continue;
        }

        bool chk = 0;
        ROF(i, n - 1, 0) {
            int need = 0;
            int nv[26];
            MEM(nv, 0);
            if(i != 0) {
                FOR(j, 0, 25) {
                    if(freq[i - 1][j] % k == 0) {
                        continue;
                    }
                    int tmp = (((freq[i - 1][j] / k) + 1) * k) - freq[i - 1][j];
                    // cout << i << " " << (((freq[i - 1][j] / k) + 1) * k) << endl;
                    need += tmp;
                    nv[ j ] += tmp;
                }
            }
            // cout << i << " : " << need << " " << n - i << endl;
            if(need <= n - i) {
                

                int cand = -1;
                FOR(j, 0, 25) {
                    if(j <= (str[i] - 'a')) {
                        continue;
                    }
                    if(nv[j]) {
                        cand = j;
                        break;
                    }
                }

                if(n - i == need && cand == -1) {
                    continue;
                }

                

                if(n - i == need) {
                    FOR(pp, 0, i - 1) {
                        cout << str[pp];
                    }
                    nv[cand]--;need--;
                    // cout << "cand : " << cand << endl;
                    cout << (char)(cand + 'a');
                }
                else if((cand == -1 || cand > (str[i] + 1 - 'a'))  && (str[i] != 'z') && (need + k <= n - i)) {
                    FOR(pp, 0, i - 1) {
                        cout << str[pp];
                    }
                    cout << (char)(str[i] + 1);
                    need += (k - 1);
                    nv[str[i] + 1 - 'a'] += (k - 1);
                }
                else if(cand == -1) {
                    continue;
                }
                else {
                    FOR(pp, 0, i - 1) {
                        cout << str[pp];
                    }
                    nv[cand]--;need--;
                    cout << (char)(cand + 'a');
                }


                FOR(pp, i + 1, n - 1) {
                    cand = -1;
                    FOR(j, 0, 25) {
                        if(nv[j]) {
                            cand = j;
                            break;
                        }
                    }
                    // cout << n - k << " " << need << endl;
                    if(n - pp == need) {
                        nv[cand]--;need--;
                        cout << (char)(cand + 'a');
                        continue;
                    }
                    
                    if(cand == -1 || cand > ('a' - 'a')) {
                        cout << (char)('a');
                    }
                    else {
                        nv[cand]--;need--;
                        cout << (char)(cand + 'a');
                    }
                    
                }
                cout << "\n";
                chk = 1;
                break;
            }
        }
        if(!chk) {
            cout << "-1\n";
        }
    }
    return 0;
}
/**
*/
