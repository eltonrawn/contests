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

int n;
int ara[MX], orig[MX];

void print_ara() {
    for(int i = 1; i <= n * 2; i ++) {
        cout << ara[i] << " ";
    }
    cout << endl;
}

void reset_ara() {
    FOR(i, 1, n * 2) {
        ara[i] = orig[i];
    }
    // print_ara();
}

bool is_sorted() {
    FOR(i, 1, n * 2) {
        if(ara[i] == i) {
            continue;
        }
        return 0;
    }
    return 1;
}

void swap_pos() {
    for(int i = 1; i <= n * 2; i += 2) {
        swap(ara[i], ara[i + 1]);
    }
    // print_ara();
}

void swap_array() {
    for(int i = 1; i <= n; i++) {
        swap(ara[i], ara[n + i]);
    }
    // print_ara();
}

int func() {
    // cout << "turn : " << turn << endl;
    // print_ara();
    if(ara[1] == 1) {
        if(!is_sorted()) {return -1000000000;}
        return 0;
    }
    swap_array();
    if(ara[1] == 1) {
        if(!is_sorted()) {return -1000000000;}
        return 1;
    }
    swap_pos();
    if(ara[1] == 1) {
        if(!is_sorted()) {return -1000000000;}
        return 2;
    }
    return 2 + func();
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n;

    FOR(i, 1, n * 2) {
        cin >> ara[i];
        orig[i] = ara[i];
    }
    if(is_sorted()) {
        cout << 0 << endl;
        return 0;
    }
    if(n % 2) {
        int mn = func();
        reset_ara();
        
        swap_pos();
        mn = min(mn, func() + 1);
        cout << max(mn, -1) << endl;
        return 0;
    }
    
    reset_ara();
    swap_pos();
    if(is_sorted()) {
        cout << 1 << endl;
        return 0;
    }
    /// revert
    reset_ara();

    swap_array();
    if(is_sorted()) {
        cout << 1 << endl;
        return 0;
    }
    /// revert
    reset_ara();

    swap_pos();
    swap_array();
    if(is_sorted()) {
        // print_ara();
        cout << 2 << endl;
        return 0;
    }
    cout << -1 << endl;
    

    return 0;
}
/**
*/
