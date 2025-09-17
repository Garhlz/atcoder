#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int cnt, head[N];
struct edge {
    int to, w, nxt;
} e[N << 1];

int vis[N], val[N], sz[N], bits[N][30], mor[N];

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

    int num = 0;  // 连通块计数
    auto bfs = [&](int start, int comp_id) {
        queue<int> q;
        q.push(start);
        vis[start] = comp_id;
        val[start] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            sz[comp_id]++;
            for (int i = head[x]; i; i = e[i].nxt) {
                int y = e[i].to, w = e[i].w;
                if (vis[y]) {
                    if ((val[x] ^ w) != val[y]) {
                        cout << -1 << '\n';
                        exit(0);
                    }
                    continue;
                }
                vis[y] = comp_id;
                val[y] = val[x] ^ w;
                q.push(y);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            num++;
            bfs(i, num);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            bits[vis[i]][j] += (val[i] >> j) & 1;
        }
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < 30; j++) {
            if (bits[i][j] > sz[i] - bits[i][j]) {
                mor[i] ^= (1 << j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (val[i] ^ mor[vis[i]]) << ' ';
    }
    cout << '\n';
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