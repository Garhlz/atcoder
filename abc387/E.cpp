#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
实际上是构造题或者说是trick题目
*/

int is_good(int x) {
    int tmp = x;
    int t = 0;
    while (tmp) {
        t += tmp % 10;
        tmp /= 10;
    }
    if (x % t == 0)
        return 1;
    else
        return 0;
}

void zero_loop(int x) {
    while (x--) cout << 0;
}

void solve() {
    string n;
    cin >> n;
    int len = n.size();
    if (len <= 6) {
        int now = 0;
        for (int i = 0; i < len; i++) {
            now = now * 10 + n[i] - '0';
        }
        for (int i = now; i < now * 2; i++) {
            if (is_good(i) && is_good(i + 1)) {
                cout << i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
        return;
    }

    int flag = 0;  // 0表示后缀全是0
    for (int i = 1; i < len; i++) {
        if (n[i] != '0') {
            flag = 1;
            break;
        }
    }

    if (!flag) {  // 后缀全是0
        int x = n[0] - '0';
        if (x != 9) {
            cout << x << 8 - x;  // 直接取即可
            zero_loop(len - 2);
            cout << '\n';
        } else {
            cout << 17;
            zero_loop(len - 1);
            cout << '\n';
        }
    } else {
        int x = n[0] - '0', y = n[1] - '0';
        if (x == 9) {
            cout << 17;
            zero_loop(len - 1);  // 多一位
            cout << '\n';
        } else if (x == 8) {
            cout << 107;
            zero_loop(len - 2);
            cout << '\n';
        } else if (x != 1) {
            cout << x + 1 << 8 - x - 1;
            zero_loop(len - 2);  // 似乎是这里写错了
            // 还真是
            cout << '\n';
        } else if (x == 1 && y >= 5) {
            cout << 26;
            zero_loop(len - 2);
            cout << '\n';
        } else {
            cout << 17;
            zero_loop(len - 2);
            cout << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
