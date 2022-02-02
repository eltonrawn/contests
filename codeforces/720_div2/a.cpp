#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

/****************************short sieve and prime fact generate start***********************************/
bool flag[10000020];
vector<LL> prime;
 
void gen_sieve(int limit)	{
    memset(flag, 0, sizeof(flag));
	int sqrt_n = sqrt(limit);
	for (int i = 3; i <= sqrt_n; i += 2)	{
		if (!flag[i])
			for(int j = i * i; j <= limit; j += (i * 2)) flag[j] = 1;
	}
	prime.clear();prime.push_back(2);
    for(int i = 3; i <= limit; i += 2)   {
        if(flag[i] == 0)prime.push_back(i);
    }
}


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    gen_sieve(10000000);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        LL a, b;
        cin >> a >> b;
        if(b == 1) {
            cout << "NO" << endl;
            continue;
        }
        LL c = b + 1;
        // for(LL val: prime) {
        //     if(b % val) {
        //         c = val;
        //         break;
        //     }
        // }
        // cout << "c : " << c << endl;
        c = 1;
        cout << "YES\n";
        cout << a * b << " " << a * c << " " << a * (b + c) << endl;
        // cout << (a * b) % (a * b) << " " << (a * c) % (a * b) << " " << (a * (b + c)) % (a * b) << endl;
        // cout << (a * b) % (a) << " " << (a * c) % (a) << " " << (a * (b + c)) % (a) << endl;
    }
    return 0;
}
/**
 * 
 * x + y = z
 * 
 * one will be divisible by a * b
 * 
 * two will be divisible by only a
 * 
 * (a * b) + (a * c) = a * (b + c)
 * (a * b) + (a * prime) = a * (b + prime)
 * 
 * (a * b) + (a * 1) = a * (b + 1)
 * 
*/
