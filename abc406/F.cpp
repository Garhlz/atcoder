#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void dfs(int x, int f, vector<int> &dfn, vector<int> &siz, vector<vector<int>> &g, int &cnt) {
    dfn[x] = cnt++;  // 记录结点的dfs序
    siz[x] = 1;
    for (auto v : g[x]) {
        if (v == f) continue;
        dfs(v, x, dfn, siz, g, cnt);
        siz[x] += siz[v];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pii> ed(n);
    vector<int> siz(n + 1);
    vector<int> dfn(n + 1);
    vector<int> c(n + 1);  // 分别是原本的权值和树状数组权值
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 1;
    dfs(1, 0, dfn, siz, g, cnt);
    for (int i = 1; i <= n; i++) {
        c[i] = i & -i;
    }
    auto add = [&](int x, int k) {
        while (x <= n) {
            c[x] += k;
            x += x & -x;  // lowbit
        }
    };

    auto getsum = [&](int x) {
        int ans = 0;
        while (x) {
            ans += c[x];
            x -= x & -x;  // lowbit
        }
        return ans;
    };
    int tot = n;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int op, x, w;
        cin >> op;
        if (op == 1) {
            cin >> x >> w;
            add(dfn[x], w);  // 更新dfs序对应的权值
            tot += w;
        } else if (op == 2) {
            cin >> x;
            auto [u, v] = ed[x];
            // 设定 u 为父结点，v 为子结点
            if (dfn[u] > dfn[v]) swap(u, v);  // 确保 u 是父结点
            int ans = getsum(dfn[v] + siz[v] - 1) - getsum(dfn[v] - 1);
            cout << abs(tot - ans * 2) << '\n';
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
/*
6
1 2
1 3
2 4
4 5
4 6
5
2 1
1 1 3
2 1
1 4 10
2 5
*/