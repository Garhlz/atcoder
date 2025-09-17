#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
string v[1003];
int dp[1003][1003];  // 到达这个格子的最小次数
int vis[1003][1003];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = " " + s;
        v[i] = s;
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<pii> q, q1;
    memset(dp, 0x3f, sizeof(dp));

    q.push({a, b});
    vis[a][b] = 1;
    dp[a][b] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        q1.push({x, y});
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (v[xx][yy] == '#') continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            dp[xx][yy] = 0;
            q.push({xx, yy});
        }
    }
    // 是不是可以改成优先队列
    while (!q1.empty()) {
        auto [x, y] = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (v[xx][yy] == '#') {
                if (dp[xx][yy] > dp[x][y] + 1) {
                    dp[xx][yy] = dp[x][y] + 1;
                    q1.push({xx, yy});
                }
                int xx1 = xx + dx[i];
                int yy1 = yy + dy[i];
                if (xx1 < 1 || xx1 > n || yy1 < 1 || yy1 > m) continue;
                if (v[xx1][yy1] == '#') {
                    if (dp[xx1][yy1] > dp[x][y] + 1) {
                        dp[xx1][yy1] = dp[x][y] + 1;
                        q1.push({xx1, yy1});
                    }
                }
            } else {
                if (vis[xx][yy]) continue;
                if (dp[xx][yy] > dp[x][y]) {
                    dp[xx][yy] = dp[x][y];
                    q1.push({xx, yy});
                }
            }
        }
    }
    cout << dp[c][d] << '\n';
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
