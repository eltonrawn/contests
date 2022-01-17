#include<bits/stdc++.h>

using namespace std;

int n;
int ara[100010];


void f3() {
    // n <= 100000
    // 1 <= ai <= 1000000000
    // f1 complexity -> 100000 * n -> 100000 * 100000 -> 10000000000 won't work
    // f2 complexity -> 100000 + n -> 100000 + 100000 -> 200000 -> O(n + max(ai))
    // f3 complexity -> n * log(n) + n -> 100000 * 20 -> 2000000 -> O(nlogn)
    /**
        5
        12 45 1 2 45

        freq ara ->
        1-> 1
        2 -> 1
        12 -> 1
        45 -> 2
    */
    map<int, int> freq;
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    
    for(int i = 1; i <= n; i++) {
        int pos = ara[i];
        freq[pos]++;
    }

    for(auto it: freq) {
        cout << it.first << " ";
    }
    cout << endl;
}

void f2() {
    // n <= 100000
    // 1 <= ai <= 100000
    // f1 complexity -> 100000 * n -> 100000 * 100000 -> 10000000000 won't work
    // f2 complexity -> 100000 + n -> 100000 + 100000 -> 200000 -> O(n + max(ai))
    /**
        5
        12 45 1 2 45

        freq ara ->
        1-> 1
        2 -> 1
        .
        .
        12 -> 1
        .
        .
        45 -> 2
        .
        .
        100000 -> 0
    */
    int freq[100010];
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int i = 1; i <= 100000; i++) {
        freq[i] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        int pos = ara[i];
        freq[pos]++;
    }

    for(int i = 1; i <= 100000; i++) {
        if(freq[i] > 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}


void f1() {
    // n <= 100000
    // 1 <= ai <= 1000
    // 1000 * n -> 1000 * 100000 -> 100000000 -> O(n * max(ai))
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ara[i];
    }
    for(int num = 1; num <= 1000; num++) {
        for(int i = 1; i <= n; i++) {
            if(num == ara[i]) {
                cout << num << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    f3();
    return 0;
}
/**
n
a1 a2 ...... an -> ai where i from 1 to n


5
12 45 1 2 45
*/
