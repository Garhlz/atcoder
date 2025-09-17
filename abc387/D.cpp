#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define tup array<int, 3>

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int dx[2][2] = {{0, 0}, {1, -1}};
int dy[2][2] = {{1, -1}, {0, 0}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    map<tup, int> vis;
    // 第一维=0表示横着到的
    int sx, sy, gx, gy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t;
            cin >> t;
            if (t == 'S') {
                sx = i, sy = j;
                a[i][j] = 1;
            } else if (t == 'G') {
                gx = i, gy = j;
                a[i][j] = 1;
            } else if (t == '.') {
                a[i][j] = 1;
            }
        }
    }
    queue<array<int, 4>> q;  // 0表示下一步横着,1表示竖着
    q.push({sx, sy, 1, 0});
    q.push({sx, sy, 0, 0});
    int ans = -1;
    int ff = 0;
    while (!q.empty()) {
        auto [x, y, flag, cnt] = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int xx = x + dx[flag][i], yy = y + dy[flag][i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || !a[xx][yy]) continue;
            if (xx == gx && yy == gy) {  // 第一个走到的就是最近的
                ans = cnt + 1;
                ff = 1;
                break;
            }
            if (ff) break;
            if (vis[{flag, xx, yy}]) continue;
            vis[{flag, xx, yy}] = 1;  // 因为是bfs,所以第一次搜到就是最短路,但要分类
            q.push({xx, yy, (flag ^ 1), cnt + 1});
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
