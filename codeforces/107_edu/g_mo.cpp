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
#define MX 200010
#define INFL 1000000000000000000LL
#define INF 1000000000
#define BLOCK 450 // ~sqrt(N)

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

struct Qdata {
    int l, r, pos;
};

class cmp {
public:
    bool operator()(Qdata x, Qdata y) {
        if(x.l/BLOCK != y.l/BLOCK) {
            // different blocks, so sort by block.
            return x.l/BLOCK < y.l/BLOCK;
        }
        // same block, so sort by R value
        return x.r < y.r;
    }
};

struct trie {
    trie *next[2];
    int cnt[2];
    trie() {
        next[0] = next[1] = NULL;
        cnt[0] = cnt[1] = 1;
    }
}*root;


int bit_mx = 20;
int n, m, q;
int ara[MX], cnt[MX], ans[MX];
vector<Qdata> qdata;
int freq[2][30];

void print_query() {
    
    cout << "0--> ";
    ROF(i, bit_mx, 0) {
        cout << freq[0][i] << " ";
    }
    cout << endl;

    cout << "1--> ";
    ROF(i, bit_mx, 0) {
        cout << freq[1][i] << " ";
    }
    cout << endl;
}

void add_val(int cur_l, int cur_r) {
    trie *curr = root;
    FOR(i, 0, bit_mx) {
        int id = 0;
        if((cur_r - cur_l) & (1 << i)) {
            id = 1;
        }
        if(curr->next[id] == NULL) {
            curr->next[id] = new trie();
        }
        curr->cnt[id] += cnt[ cur_r ];
        freq[id][i] += cnt[ cur_r ];
        curr = curr->next[id];
    }
    // cout << "after add_val " << cur_l << " " << cur_r << endl;
    // print_query();
}

void remove_val(int cur_l, int cur_r) {
    trie *curr = root;
    FOR(i, 0, bit_mx) {
        int id = 0;
        if((cur_r - cur_l) & (1 << i)) {
            id = 1;
        }
        // if(curr->next[id] == NULL) {
        //     curr->next[id] = new trie();
        // }
        curr->cnt[id] -= cnt[ cur_r ];
        freq[id][i] -= cnt[ cur_r ];
        curr = curr->next[id];
    }
    // cout << "after remove_val " << cur_l << " " << cur_r << endl;
    // print_query();
}

bool query() {
    FOR(i, 0, bit_mx) {
        if(freq[1][i] % 2) {
            return 1;
        }
    }
    return 0;
}

void add_l() {
    trie *curr = root;
    FOR(i, 0, bit_mx) {
        /// all zeroes become one
        /// all ones become zero and propogate
        
        freq[0][i] -= curr->cnt[0];freq[1][i] -= curr->cnt[1];
        swap(curr->next[0], curr->next[1]);
        swap(curr->cnt[0], curr->cnt[1]);
        freq[0][i] += curr->cnt[0];freq[1][i] += curr->cnt[1];
        int id = !1;

        if(curr->next[id] == NULL) {
            break;
        }
        curr = curr->next[id];
    }
    // cout << "after add_l" << endl;
    // print_query();
}

void remove_l() {
    trie *curr = root;
    FOR(i, 0, bit_mx) {
        /// all zeroes become one
        /// all ones become zero and propogate
        
        freq[0][i] -= curr->cnt[0];freq[1][i] -= curr->cnt[1];
        swap(curr->next[0], curr->next[1]);
        swap(curr->cnt[0], curr->cnt[1]);
        freq[0][i] += curr->cnt[0];freq[1][i] += curr->cnt[1];
        int id = !0;

        if(curr->next[id] == NULL) {
            break;
        }
        curr = curr->next[id];
    }
    // cout << "after remove_l" << endl;
    // print_query();
}

void mos() {
    sort(qdata.begin(), qdata.end(), cmp());

	int cur_l = 0, cur_r = 0;
	for(int i = 0; i < qdata.size(); i++) {
		int l = qdata[i].l, r = qdata[i].r;
        // cout << "qlr : " << l << " " << r << endl;

		while(cur_l > l) {
			cur_l--;
            add_l();
            add_val(cur_l, cur_l);
		}
        

        while(cur_r < r) {
			cur_r++;
            add_val(cur_l, cur_r);
		}
        

		while(cur_l < l) {
            if(cur_l != 0) {
                remove_val(cur_l, cur_l);    
            }
            remove_l();
            cur_l++;
		}

		while(cur_r > r) {
			remove_val(cur_l, cur_r);
			cur_r--;
		}

        // cout << "cur_l : " << cur_l << endl;
        // cout << "cur_r : " << cur_r << endl;
		ans[qdata[i].pos] = query();
	}
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    FastIO;
    cin >> n >> m;
    FOR(i, 1, n) {
        cin >> ara[i];
        cnt[ ara[i] ]++;
    }
    cin >> q;
    FOR(i, 0, q - 1) {
        int l, r;
        cin >> l >> r;
        qdata.PB({l, r, i});

    }
    root = new trie();
    mos();
    // sort(qdata.begin(), qdata.end(), cmp1());
    FOR(i, 0, q - 1) {
        cout << (ans[i] == 0 ? 'B' : 'A');
    }
    cout << endl;

    return 0;
}
/**
 * 89442719
*/
