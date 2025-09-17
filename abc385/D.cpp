#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

map<int, set<int>> mpx, mpy;
int ans = 0;

void func(int x, int y, int u, int v, map<int, set<int>>& a, map<int, set<int>>& b) {
    if (a[x].empty() || abs(x) > 1e9 || abs(y) > 1e9) return;
    vector<int> tmp;
    auto st = a[x].lower_bound(y + u);
    auto ed = a[x].upper_bound(y + v);
    for (auto it = st; it != ed; it++) {
        ans++;
        tmp.push_back(*it);  // 需要删除的房屋,已经访问过,只会删除一次
    }
    for (int t : tmp) {
        b[t].erase(x);
        a[x].erase(t);
        // 分别从以行存储的和以列存储的点数组中删除已经访问过的房屋位置
    }
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        mpx[u].insert(v);
        mpy[v].insert(u);
    }

    for (int i = 1; i <= m; i++) {
        char op;
        int d;
        cin >> op >> d;
        if (op == 'U') func(x, y, 0, d, mpx, mpy), y += d;
        if (op == 'D') func(x, y, -d, 0, mpx, mpy), y -= d;
        if (op == 'L') func(y, x, -d, 0, mpy, mpx), x -= d;
        if (op == 'R') func(y, x, 0, d, mpy, mpx), x += d;
    }
    cout << x << ' ' << y << ' ' << ans << '\n';
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
