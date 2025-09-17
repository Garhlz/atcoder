#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
// 直接对图离散化
void solve() {
    int n, m;
    cin >> n >> m;
    // vector<int> b(n + 1, 0), w(n + 1, n + 1);
    // 同一行最右的黑,最左的白
    map<int, int> b, w;

    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'B') {
            if (!b.count(x)) b[x] = 0;  // 小小的初始化
            b[x] = max(b[x], y);
        } else if (c == 'W') {
            if (!w.count(x)) w[x] = n + 1;
            w[x] = min(w[x], y);
        }
    }
    /*
    接下来要离散化,把两个map合并,中间没有涉及的行或者列都可以无视之
    */

    set<int> st;
    for (auto h : w) st.insert(h.first);
    for (auto h : b) st.insert(h.first);

    int cnt = st.size();
    vector<int> ww(cnt), bb(cnt);
    int now = 0;
    for (auto k : st) {
        if (!w.count(k))
            ww[now] = n + 1;
        else
            ww[now] = w[k];

        if (!b.count(k))
            bb[now] = 0;
        else
            bb[now] = b[k];

        now++;
    }

    for (int i = 0; i < cnt; i++) {
        if (ww[i] <= bb[i]) {
            cout << "No\n";
            return;
        }
    }
    // 没有判断列是否成立,不知道是否可以
    // 确实可以,思路对了(直觉)
    for (int i = 1; i < cnt; i++) {
        ww[i] = min(ww[i], ww[i - 1]);  // 前缀最小值
    }

    for (int i = cnt - 1; i >= 0; i--) {
        if (ww[i] <= bb[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
