#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 100010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

/****************************short sieve and prime fact generate start***********************************/
bool flag[1000020];
vector<int> prime;
 
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
 
vector<PII> fact;
void prime_fact(LL tmp)  {
    fact.clear();
    LL sqrtn;
    sqrtn = sqrt(tmp);
    for(LL i = 0; prime[i] <= sqrtn; i++)   {
        if(tmp % prime[i] == 0) {
            LL cnt = 0;
            while(tmp % prime[i] == 0) {
                tmp /= prime[i];
                cnt++;
            }
            fact.push_back({prime[i], cnt});
        }
        sqrtn = sqrt(tmp);
    }
    if(tmp != 1)    {
        LL cnt = 1;
        fact.push_back({tmp, cnt});
    }
    // sort(fact.begin(), fact.end());
}
/****************************short sieve and prime fact generate end***********************************/

int lg = 20;
vector<vector<int>> up;
int n, q;
int ara[SZ];
int go[SZ], mn_pr[SZ];
vector<int> adjl[SZ];

void dfs(int v, int p)
{
    
    up[v][0] = p;

    for (int i = 1; i <= lg; ++i) {
        // cout << i << endl;
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adjl[v]) {
        if (u != p)
            dfs(u, v);
    }
}

int traverse(int l, int r) {
    if(l == r) {
        return 0;
    }
    // cout << l << " " << r << endl;
    int pos = -1;
    for(int i = 0; i <= lg; i++) {
        // cout << i << " : " << up[l][i] << endl;
        if(up[l][i] == 0) {
            continue;
        }
        if(up[l][i] <= r) {
            pos = i;
        }
        else {
            break;
        }
    }
    if(pos == -1) {
        // cout << "hi" << endl;
        return 0;
    }
    return (1 << pos) + traverse(up[l][pos], r);
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    gen_sieve(1000000);
    cin >> n >> q;
    up.assign(n + 1, vector<int>(lg + 1));
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i <= n + 1; i++) {
        go[i] = mn_pr[i] = n + 1;
    }
    for(int i = n; i >= 1; i--) {
        prime_fact(ara[i]);
        go[i] = go[i + 1];
        for(PII pr: fact) {
            int val = pr.first;
            go[i] = min(go[i], mn_pr[val]);
        }
        adjl[go[i]].push_back(i);
        for(PII pr: fact) {
            int val = pr.first;
            mn_pr[val] = i;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << i << " : " << go[i] << endl;
    // }

    for(int i = n; i >= 1; i--) {
        if(go[i] == n + 1) {
            dfs(i, 0);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << i << " : ";
    //     for(int j = 0; j <= lg; j++) {
    //         cout << up[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << 1 + traverse(l, r) << endl;
    }

    return 0;
}
/**
 * 
 * tags: binary lifting
*/
