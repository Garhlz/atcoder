#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 3>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int high(int x) {
    for (int i = 60; i >= 0; i--) {
        if (x & (1ll << i)) {
            return i;
        }
    }
    return -1;
}
int ans;
void dfs(int cnt, int now, vector<vector<int>> &g, vector<vector<pii>> &num, map<pii, int> &mp) {
    if (now == -1) {
        ans = max(ans, cnt);
        return;
    }
    int flag = 0;
    for (auto [x, y, op] : num[now]) {
        if (!op) {
            if (g[x][y] || g[x][y + 1]) continue;
            g[x][y] = 1;
            g[x][y + 1] = 1;
        } else {
            if (g[x][y] || g[x + 1][y]) continue;
            g[x][y] = 1;
            g[x + 1][y] = 1;
        }

        dfs(cnt ^ mp[{x, y, op}], now - 1, g, num, mp);
        flag = 1;
        if (!op) {
            // if (g[x][y] || g[x][y + 1]) continue;
            g[x][y] = 0;
            g[x][y + 1] = 0;
        } else {
            // if (g[x][y] || g[x + 1][y]) continue;
            g[x][y] = 0;
            g[x + 1][y] = 0;
        }
    }
    // 不取当前位, 或者没有
    dfs(cnt, now - 1, g, num, mp);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> h(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
            ans ^= h[i][j];
        }
    }
    map<pii, int> mp;
    vector<vector<pii>> num(61);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            int now = h[i][j] ^ h[i][j + 1];
            mp[{i, j, 0}] = now;
            int tmp = high(now);
            if (tmp != -1) num[tmp].push_back({i, j, 0});
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            int now = h[i][j] ^ h[i + 1][j];
            mp[{i, j, 1}] = now;
            int tmp = high(now);
            if (tmp != -1) num[tmp].push_back({i, j, 1});
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    dfs(0, 60, vis, num, mp);
    cout << ans << '\n';
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
