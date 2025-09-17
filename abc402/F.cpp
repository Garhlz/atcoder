#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
int b[405], d[25][25], a[25][25];
vector<vector<vector<int>>> c;
int n, m;

void dfs(int op, int x, int y, int s) {
    if (x + y == n + 1) {
        if (op) s = (s + a[x][y]) % m;
        c[op][x].emplace_back(s);
        return;
    }
    s = (s + a[x][y]) % m;
    if (op) {
        if (x > 1) dfs(op, x - 1, y, s);
        if (y > 1) dfs(op, x, y - 1, s);
    } else {
        if (x < n) dfs(op, x + 1, y, s);
        if (y < n) dfs(op, x, y + 1, s);
    }
}

void solve() {
    cin >> n >> m;
    c.resize(2, vector<vector<int>>(n + 1));
    int N = 2 * n - 1;
    b[1] = 1;
    for (int i = 2; i <= N; i++) b[i] = (b[i - 1] * 10) % 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            a[i][j] = (d[i][j] % m) * (b[N - i - j + 2] % m) % m;
        }
    }
    dfs(0, 1, 1, 0);
    dfs(1, n, n, 0);
    for (int i = 1; i <= n; i++) {
        sort(all(c[0][i]));
        sort(all(c[1][i]));
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = c[1][i].size() - 1;
        for (int j = 0; j < c[0][i].size(); j++) {
            if (k >= 0) ans = max(ans, (c[0][i][j] + c[1][i][k]) % m);
            while (k >= 0 && c[0][i][j] + c[1][i][k] >= m) k--;
            if (k >= 0) ans = max(ans, (c[0][i][j] + c[1][i][k]) % m);
        }
    }
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
