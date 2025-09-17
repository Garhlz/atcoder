#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define tup array<int, 3>

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int sx, sy;
    cin >> sx >> sy;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    vis[sx][sy] = 1;
    int now = g[sx][sy];
    int x = sx, y = sy;

    // 初始点坐标
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
        if (vis[xx][yy]) continue;  // 这里导致越界, 应该放在后方即可
        // if(g[xx][yy] * k >= now)continue;此时不考虑
        pq.push({g[xx][yy], xx, yy});  // 第一次入队vis, 后续不可重复入队
        vis[xx][yy] = 1;
    }

    while (!pq.empty()) {
        auto [val, x, y] = pq.top();
        pq.pop();

        if ((__int128)val * k >= (__int128)now) {  // 贪心地取最小的相邻结点, 注意这里要使用__int128
            break;
        }
        now += val;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            pq.push({g[xx][yy], xx, yy});
        }
    }
    cout << now << '\n';
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
