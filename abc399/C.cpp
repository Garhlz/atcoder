#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;

vector<int> v[N];
int vis[N], ans;
void dfs(int x, int f) {
    for (int y : v[x]) {
        if (y == f) continue;
        if (vis[y]) {
            ans++;
            continue;
        }
        vis[y] = 1;
        dfs(y, x);
    }
}
/*
是不是因为要求是至少要删除的边的数量
*/
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i, 0);
        }
    }
    cout << ans / 2 << '\n';
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
