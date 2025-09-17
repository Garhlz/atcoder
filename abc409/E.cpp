#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct edge {
    int to, nxt, w;
} e[N << 1];

int cnt, head[N], a[N];
void add(int u, int v, int w) {
    e[++cnt] = {v, head[u], w};
    head[u] = cnt;
}
int ans = 0;

int dfs(int x, int f) {
    int now = a[x];
    for (int i = head[x]; i; i = e[i].nxt) {
        auto [y, _, w] = e[i];
        if (y == f) continue;
        int son_value = dfs(y, x);
        ans += abs(son_value) * w;
        now += son_value;
    }
    return now;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
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
