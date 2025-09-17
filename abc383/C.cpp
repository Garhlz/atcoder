#include <bits/stdc++.h>
using namespace std;

#define pii array<int, 2>
#define tup array<int, 3>

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, d + 1));
    vector<pii> h;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'H') {
                h.push_back({i, j});
                vis[i][j] =
                    0;  // 真的是, 如果给出的数据是全部都为H的图,时间可能会非常长, 因此直接剪枝掉即可, 剪枝之后就ok了
                ans++;
            }
        }
    }

    for (auto [sx, sy] : h) {
        queue<tup> q;
        // 一开始推入的是起始点的相邻点,而不是起始点自己
        for (int i = 0; i < 4; i++) {
            int xx = sx + dx[i], yy = sy + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if (g[xx][yy] == '#') continue;
            q.push({xx, yy, 1});  // 懒得去重了
        }

        while (!q.empty()) {
            auto [x, y, step] = q.front();
            q.pop();
            if (step >= vis[x][y]) continue;

            if (vis[x][y] == d + 1) {  // 只有未访问过才会加, 除了h的点之外
                ans++;
            }

            vis[x][y] = step;  // 已经用了这么多步数走到这里

            if (step == d) continue;  // 不能再走下去了

            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
                if (g[xx][yy] == '#') continue;
                q.push({xx, yy, step + 1});  // 懒得去重了
            }
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
