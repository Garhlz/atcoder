#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int ans;
int n, m, k;
vector<vector<int>> a, vis;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, int level) {
    if (level == k) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || yy < 1 || xx > n || yy > m || vis[xx][yy] || a[xx][yy]) continue;
        vis[xx][yy] = 1;
        dfs(xx, yy, level + 1);
        vis[xx][yy] = 0;
    }
}

void solve() {
    cin >> n >> m >> k;

    a.resize(n + 1, vector<int>(m + 1));
    vis.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!a[i][j]) {
                vis[i][j] = 1;
                dfs(i, j, 0);
                vis[i][j] = 0;
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
