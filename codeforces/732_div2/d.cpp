#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 200010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
}

int n;
string str;
LL F[SZ], rF[SZ];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    F[0] = rF[0] = 1;
    for(LL i = 1; i < SZ; i++) {
        F[i] = i * F[i - 1] % MOD;
        rF[i] = inv(i, MOD) * rF[i - 1] % MOD;
    }

    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> str;
        int a = 0;
        int b = 0;
        for(int i = 0; i < str.size();) {
            if(str[i] == '0') {a++; i++; continue;}
            if(i == str.size() - 1) break;
            if(str[i + 1] == '0') {a++; i += 2; continue;}
            b++; i += 2;
        }
        cout << F[a + b] * rF[a] % MOD * rF[b] % MOD << endl;
    }
    return 0;
}
/**
010011
011100
110100

000011000000

000001111111111111000000000

0000100001100
0000111000000

0000100001001111
0000111000010011

0000011

1100
0011

1100
0110
0011


00000110000000
00000000000011

000001110000000
0000010110000111

11 10
10 11


10001111111000011

10 0 0 _ _ _ X X X X X

00111

0 0 11

0 01 11

01 11
11 01

_ _ _ _ _ _ X X X X X

(n + m)! / n! / m!

1 3 4 5
1 3 5 4
1 4 3 5


_ _ _ _ _ _ X X X X X E E E E
..

a m
6 9 -> gcd(6, 9) = 2

0 6 3 0

0 3 6 9

*/
