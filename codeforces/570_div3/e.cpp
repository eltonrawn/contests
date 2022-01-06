#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

class Node {
public:
    Node* nxt[30];
    int pos;
    Node() {
        pos = -1;
        for(int i = 0; i < 30; i++) {
            nxt[i] = NULL;
        }
    }
    Node(int pp) {
        pos = pp;
        for(int i = 0; i < 30; i++) {
            nxt[i] = NULL;
        }
    }
};

int n, k;
string str;
vector<int> vv[30];
Node *root;
int taken = 0;
int ans = 0;

int get_nxt_pos(int pos, int ch) {
    int pp = upper_bound(vv[ch].begin(), vv[ch].end(), pos) - vv[ch].begin();
    if(pp == vv[ch].size()) return -1;
    return vv[ch][pp];
}

void ins(Node *cur, int cur_len, int total_len, int nxt_pos) {
    if(cur_len == total_len) return;
    int ch = str[nxt_pos] - 'a';
    cur->nxt[ch] = new Node(nxt_pos);
    ins(cur->nxt[ch], cur_len + 1, total_len, nxt_pos + 1);
}

void func(Node *cur, int cur_len, int total_len) {
    if(taken == k) return;
    if(cur_len == total_len) return;
    for(int i = 0; i < 30; i++) {
        if(cur->nxt[i] == NULL) {
            /// find next position
            int nxt_pos = get_nxt_pos(cur->pos, i);
            if(nxt_pos == -1) continue;
            // cout << "nxt_pos" << nxt_pos << endl;
            if(cur_len + (str.size() - nxt_pos) >= total_len) {
                ins(cur, cur_len, total_len, nxt_pos);
                taken++;
                ans += str.size() - total_len;
                if(taken == k) {
                    return;
                }
            }
        }
    }

    for(int i = 0; i < 30; i++) {
        if(cur->nxt[i] != NULL) {
            func(cur->nxt[i], cur_len + 1, total_len);
        }
    }
}

void del_trie(Node *cur) {
    for(int i = 0; i < 30; i++) {
        if(cur->nxt[i] != NULL) {
            del_trie(cur->nxt[i]);
        }
    }
    delete(cur);
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        vv[str[i] - 'a'].push_back(i);
    }

    for(int i = str.size(); i >= 0; i--) {
        if(taken == k) {
            break;
        }
        if(i == 0) {
            taken++; ans += str.size();
            break;
        }
        root = new Node();
        func(root, 0, i);
        del_trie(root);
        // cout << i << " " << taken << " " << ans << endl;
    }

    if(taken != k) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
/**
start: 4:26 pm
idea: 4:51 pm
end: 5:32 pm
duration: 1 hr 6 mins

tags: trie, repeat
comment: should have solved faster maybe. had to do some debug which slowed down
*/
