#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

struct Data {
    int mn;
    int val;
    int x;
    int y;
};

class cmp1 {
public:
    bool operator()(Data x, Data y) {
        if(x.mn == y.mn) {
            if(x.val == y.val) {
                if(x.x == y.x) {
                    return x.y < y.y;
                }
                return x.x < y.x;
            }
            return x.val > y.val;
        }
        return x.mn < y.mn;
    }
};

int n;
int ara[510];
// set< pair < pair<int, int>, pair<int, int> > > st;
set< Data, cmp1 > st;
int mnxy[510];
int taken[510];
int place[510][510];

bool is_val(int x, int y) {
    if(x > n || y > n || x <= 0 || y <= 0) {
        return 0;
    }
    if(y <= x) {
        return 1;
    }
    return 0;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
        if(i == 1 || i == n) {
            st.insert({1, ara[i], i, i});
            mnxy[ ara[i] ] = 1;
        }
        else {
            st.insert({2, ara[i], i, i});
            mnxy[ ara[i] ] = 2;
        }
        place[i][i] = ara[i];
        taken[ ara[i] ] = 1;
    }

    // for(Data data: st) {
    //     cout << data.mn << " " << data.val << " " << data.x << " " << data.y << endl;
    // }
    // cout << endl << endl;

    while(!st.empty()) {
        Data data = *st.begin();
        st.erase(st.begin());
        // cout << "data : " << data.mn << " " << data.val << " " << data.x << " " << data.y << endl;
        if(taken[data.val] == data.val) {
            continue;
        }
        if(data.mn == 0) {
            // this is not needed
            continue;
        }
        int nx, ny;
        for(int i = 0; i < 4; i++) {
            int rx = data.x + fx[i];
            int ry = data.y + fy[i];
            if(is_val(rx, ry) == 0) {continue;}
            // cout << rx << " " << ry << endl;
            if(place[rx][ry] == 0) {
                nx = rx;
                ny = ry;
                break;
            }
        }

        // cout << "nxy : " << nx << " " << ny << endl;

        for(int i = 0; i < 4; i++) {
            int rx = nx + fx[i];
            int ry = ny + fy[i];
            if(is_val(rx, ry) == 0) {continue;}

            if(place[rx][ry] && place[rx][ry] != data.val) {
                Data rdata = *st.find({mnxy[ place[rx][ry] ], place[rx][ry], rx, ry});
                st.erase(rdata);
                rdata.mn--;
                mnxy[ place[rx][ry] ]--;
                st.insert(rdata);
                // cout << "minus : " << rx << " " << ry << endl;
            }
        }


        
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int rx = nx + fx[i];
            int ry = ny + fy[i];
            if(is_val(rx, ry) == 0) {continue;}

            if(place[rx][ry] == 0) {
                cnt++;
            }
        }
        
        place[nx][ny] = data.val;
        taken[data.val]++;
        // data.mn = cnt;
        mnxy[ data.val ] = cnt;
        st.insert({mnxy[data.val], data.val, nx, ny});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!place[i][j]) {continue;}
            cout << place[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
/**
 * 125000000
*/
