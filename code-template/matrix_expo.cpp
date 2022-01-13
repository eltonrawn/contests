#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n;

int ff(int pos, int sym_no) {
    if(pos > n) return 1;
    int ans = 0;

    /// assigning this
    ans += ff(pos + 1, sym_no);
    /// no assigning this;
    if(sym_no < 4)
        ans += ff(pos, sym_no + 1);
    return ans;
}

int func(int pos, int sym_no) {
    if(pos > n) return 1;
    int ans = 0;

    for(int s = sym_no; s <= 4; s++) {
        ans += func(pos + 1, s);
    }
    return ans;
}

class matrix {
public:
    // LL v[4][4];
    vector< vector <int > > v;
    int row, col; // number of row and column

    matrix(int rr, int cc) {
        for(int i = 0; i < rr; i++) {
            vector<int> tmp;
            for(int j = 0; j < cc; j++) {
                tmp.push_back(0);
            }
            v.push_back(tmp);
            
        }
        row = v.size();
        col = v[0].size();
        // cout << row << " " << col << endl;
    }
    
    matrix(vector< vector<int> > ara) {
        v = ara;
        row = v.size();
        col = v[0].size();
        // cout << row << " " << col << endl;
    }
};
//int mod = 10000;
 
// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b) {
    // assert(a.col == b.row);
    matrix r = matrix(a.row, b.col);
    // r.row = a.row;
    // r.col = b.col;
    for (int i = 0; i < r.row; i++) {
        for (int j = 0; j < r.col; j++) {
            LL sum = 0;
            for (int k = 0; k < a.col;  k++) {
                sum += a.v[i][k] * b.v[k][j];
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}
 
// returns mat^p
matrix power(matrix mat, int p) {
    // assert(p >= 1);
    // if (p == 0) return 
    if (p == 1) return mat;
    if (p % 2 == 1) return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if(n == 1) {
        cout << 4 << endl;
        return 0;
    }
    vector< vector<int> > v1({{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}});
    // cout << "hi1" << endl;
    matrix m1 = matrix(v1);
    m1 = power(m1, n - 1);
    // cout << "hi2" << endl;

    vector< vector<int> > v2({{1}, {2}, {3}, {4}});
    matrix m2 = matrix(v2);
    cout << ff(1, 1) << " ";
    cout << func(1, 1) << " ";
    cout << multiply(m1, m2).v[3][0] << endl;
    
    return 0;
}
/**
start: 6:04 pm
tags: matrix exponentiation, matrix expo
*/
