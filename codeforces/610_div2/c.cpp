#include<bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define SZ 300010
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

LL n, t, a, b;
LL hard[SZ];
PLL m_time[SZ];


LL get_ex(LL rest, LL easy_a, LL hard_a) {
    // cout << "hoo : " << rest << " " << easy_a << " " << hard_a << " ";
    LL easy_u = min(rest / a, easy_a);
    rest -= easy_u * a;

    LL hard_u = min(rest / b, hard_a);
    // cout << easy_u + hard_u << endl;
    return easy_u + hard_u;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++) {
        cin >> n >> t >> a >> b;
        
        LL easy_a = 0, hard_a = 0;
        
        for(int i = 1; i <= n; i++) {
            cin >> hard[i];
            if(hard[i])  hard_a++;
            else easy_a++;
        }
        for(int i = 1; i <= n; i++) {
            cin >> m_time[i].first;
            m_time[i].second = i;
        }
        sort(m_time + 1, m_time + n + 1);

        
        
        LL ans = 0;
        LL t_done = 0;
        for(int le = 1; ; ) {
            while(le <= n && m_time[le].first <= t_done) {
                if(hard[m_time[le].second]) {t_done += b; hard_a--;}
                else {t_done += a; easy_a--;}

                le++;
            }

            if(t_done <= t) {
                if(le == n + 1)
                    ans = le - 1;
                else 
                    ans = max(ans, le - 1 + get_ex(m_time[le].first - t_done - 1, easy_a, hard_a));
            }
            else break;

            if(le > n) break;

            if(hard[m_time[le].second]) {t_done += b; hard_a--;}
            else {t_done += a; easy_a--;}

            le++;

        }

        // cout << "ans : ";
        cout << ans << endl;
    }
    
    return 0;
}
/**
start: 1:52 am
end: 2:42 am
duration: 50 mins
comment: time pretty bad. Time mostly taken due to stupid mistakes and debugging.
*/
