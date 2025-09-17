#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 3>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int ans;
void dfs(int now, int id, vector<vector<int>> &g, vector<vector<int>> &vis, vector<pii> &a) {
    ans = max(ans, now);
    if (id == a.size()) return;
    auto [x, y, op] = a[id];
    if (!op) {
        if (!vis[x][y] && !vis[x][y + 1]) {
            vis[x][y] = vis[x][y + 1] = 1;
            dfs(now ^ g[x][y] ^ g[x][y + 1], id + 1, g, vis, a);
            vis[x][y] = vis[x][y + 1] = 0;
        }
    } else {
        if (!vis[x][y] && !vis[x + 1][y]) {
            vis[x][y] = vis[x + 1][y] = 1;
            dfs(now ^ g[x][y] ^ g[x + 1][y], id + 1, g, vis, a);
            vis[x][y] = vis[x + 1][y] = 0;
        }
    }

    dfs(now, id + 1, g, vis, a);
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
    vector<pii> a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            a.push_back({i, j, 0});
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            a.push_back({i, j, 1});
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    dfs(ans, 0, h, vis, a);
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
/*
4 5
74832 16944 58683 32965 97236
52995 43262 51959 40883 58715
13846 24919 65627 11492 63264
29966 98452 75577 40415 77202
*/