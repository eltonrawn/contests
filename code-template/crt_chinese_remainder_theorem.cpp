#include<bits/stdc++.h>

#define LL long long

using namespace std;

LL ext_gcd (LL A, LL B, LL *X, LL *Y){
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L (LCM(m1, m2, ....))
*/
pair<LL, LL> chinese_remainder_theorem(vector<LL> A, vector<LL> M) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    LL a1 = A[0];
    LL m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        LL a2 = A[i];
        LL m2 = M[i];
 
        LL g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        LL p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        LL mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        LL x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}

void visualize_a_case(int n, int m) {
    int a = 1;
    int b = 1;
    int lcmm = n / __gcd(n, m) * m;
    for(int i = 1; i <= 2 * lcmm; i++) {
        if(a == n && b == m) {
            cout << "------------------------------------------------>";
        }
        cout << i << " : " << a << " " << b << endl;
        
        a++;
        b++;
        if(a > n) {
            a = 1;
        }
        if(b > m) {
            b = 1;
        }
    }
}

int main() {
    
    pair<int, int> yo;
    /**
     * check co-prime
     * x % 7 = 6
     * x % 5 = 3
     * x is the ans
    */
    yo = chinese_remainder_theorem({6, 3}, {7, 5});
    cout << yo.first << " " << yo.second << endl;

    /**
     * check non co-prime
     * x % 21 = 14
     * x % 15 = 2
     * x is the ans
     * 
     * you can visualize this case in function visualize_a_case()
    */
    yo = chinese_remainder_theorem({14, 2}, {21, 15});
    cout << yo.first << " " << yo.second << endl;

    visualize_a_case(21, 15);
}
/**
 * tags: crt, chinese remainder theorem, number theory
 * 
 * resources: 
 * 1. https://forthright48.com/extended-euclidean-algorithm/
 * 2. https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli/
 * 3. https://forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/
 * 
 * problems: cf_707_div1_B
*/