#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 202;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int cnt, head[N];

struct edge {
    int to, w, nxt;
} e[N];

void add(int a, int b, int c) {
    e[++cnt] = {b, c, head[a]};
    head[a] = cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int ans = (1ll << 60);
    vector<int> vis(n + 1, 0);
    function<void(int, int)> dfs = [&](int x, int now) {
        if (x == n) {
            ans = min(ans, now);
            return;
        }
        for (int i = head[x]; i; i = e[i].nxt) {
            auto [y, w, _] = e[i];
            if (vis[y]) continue;
            vis[y] = 1;
            dfs(y, now ^ w);
            vis[y] = 0;
        }
    };
    vis[1] = 1;
    dfs(1, 0);
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
