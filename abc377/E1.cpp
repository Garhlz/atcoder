#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int qpow(int a, int b, int mod) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), inverse_map(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], inverse_map[a[i]] = i;
    int cnt = 0;
    vector<int> vis(n + 1), pos(n + 1);
    vector<vector<int>> v(n + 1);
    // 用来存放每个环的元素(既是下标又是内容)
    function<void(int, int)> dfs = [&](int x, int cnt) {
        if (vis[x]) return;
        vis[x] = 1;
        v[cnt].push_back(x);
        pos[x] = v[cnt].size() - 1;
        dfs(a[x], cnt);
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, cnt++);
    }

    vector<int> ans(n + 1);

    for (int i = 0; i < cnt; i++) {
        for (int x : v[i]) {
            int len = v[i].size();
            int p1 = (pos[x] + qpow(2ll, k, len) - 1 + len) % len;
            ans[inverse_map[x]] = v[i][p1];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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