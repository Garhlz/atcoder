#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 102;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int dis[N][N], fa[N][20], dep[N];
vector<int> q[N];

void dfs(int x, int f) {
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= log2(dep[x]) + 1; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }

    for (int y : q[x]) {
        if (y != f) dfs(y, x);
    }
}

int lca(int x, int y) {
    if (x == y) return x;
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] > dep[y]) {
        x = fa[x][(int)log2(dep[x] - dep[y])];
    }
    if (x == y) return x;
    for (int i = (int)log2(dep[x]); i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    dfs(1, 0);
    map<pii, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int LCA = lca(i, j);
            int now = dep[i] + dep[j] - 2 * dep[LCA];
            if (now & 1 && now > 1) {  // 距离是奇数,表示链上的数量是偶数
                mp[{i, j}] = 1;
            }
        }
    }
    int cnt = mp.size();
    auto out = [&]() {
        auto a = mp.begin()->first;
        cout << a[0] << ' ' << a[1] << '\n';
        mp.erase(mp.begin());
    };
    // cout << "cnt=" << cnt << '\n';
    if (cnt & 1) {
        cout << "First\n";
        for (int i = 0; i < cnt / 2; i++) {
            out();
            int p, q;
            cin >> p >> q;
            if (p > q) swap(p, q);
            mp.erase(mp.find({p, q}));
        }
        out();
        int p, q;
        cin >> p >> q;
        return;
    } else {
        cout << "Second\n";
        for (int i = 0; i < cnt / 2; i++) {
            int p, q;
            cin >> p >> q;
            if (p > q) swap(p, q);
            mp.erase(mp.find({p, q}));
            out();
        }
        int p, q;
        cin >> p >> q;
        return;
    }
}

signed main() {
    solve();
    return 0;
}
