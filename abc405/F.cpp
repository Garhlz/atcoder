#include <bits/stdc++.h>
using namespace std;

struct event {
    int y, z, id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<event>> v(n * 2 + 1, vector<event>());
    vector<int> tr(2 * n + 1, 0);

    auto add = [&](int x, int y) {
        for (; x <= 2 * n; x += (x & -x)) tr[x] += y;
    };

    auto sum = [&](int x) {
        int res = 0;
        for (; x; x -= (x & -x)) res += tr[x];
        return res;
    };
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, 0, 0});
    }
    int q;
    cin >> q;
    vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        // 扫描到x的时候, 计算从x到n的区间和
        v[x].push_back({x, 1, i});
        v[x].push_back({y, -2, i});
        v[y].push_back({y, 1, i});
    }
    int tot = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 0) {
            for (auto &e : v[i]) {
                int y = e.y;
                tot++;
                add(y, 1);
            }
        } else {
            for (auto &e : v[i]) {
                int y = e.y, z = e.z, id = e.id;
                ans[id] += z * (tot - sum(y));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
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
