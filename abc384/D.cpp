#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n + 1), suf(n + 2), pre(n + 1);
    set<int> p, s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        p.insert(pre[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
        s.insert(suf[i]);
    }

    int tot = pre[n];

    p.insert(0);
    s.insert(0);
    if (sum < tot) {
        for (int i = 1; i <= n; i++) {
            if (p.find(pre[i] - sum) != p.end()) {
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
    } else {
        sum %= tot;
        for (int i = 0; i <= n; i++) {
            int suf_cur = sum - pre[i];        // 莫名写错了
            if (s.find(suf_cur) != s.end()) {  // 在后缀中查找
                cout << "Yes\n";
                return;
            }
        }
        sum += tot;  // 有可能中间多减了一个, 只需加回来就好
        for (int i = 0; i <= n; i++) {
            int suf_cur = sum - pre[i];        // 莫名写错了
            if (s.find(suf_cur) != s.end()) {  // 在后缀中查找
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
    }
}
/*
有多种情况
1. pre + 循环 + suf
2. 循环 + suf
3. pre + 循环
4. 中间
用set分别存储前缀后缀, 直接find即可
*/
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
