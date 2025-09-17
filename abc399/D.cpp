#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii array<int, 2>
const int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 5, 0);
    vector<pii> pos(n + 5);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (!pos[a[i]][0])
            pos[a[i]][0] = i;
        else
            pos[a[i]][1] = i;
    }
    int ans = 0;

    auto func = [&](int p, int q) {
        if (p < 1 || p > n * 2 || q < 1 || q > n * 2) return 0;  // 又没有判断越界的问题了
        if (abs(p - q) <= 1) return 0;                           // 真的不带脑子,这都能错啊
        // 没救了
        if (a[p] == a[q]) return 1;
        return 0;
    };

    for (int i = 1; i <= n; i++) {
        int p1 = pos[i][0], p2 = pos[i][1];
        if (abs(p1 - p2) == 1) continue;

        ans += func(p1 - 1, p2 - 1) + func(p1 - 1, p2 + 1) + func(p1 + 1, p2 - 1) + func(p1 + 1, p2 + 1);
        // 显然最多只能有两个
    }
    cout << ans / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
