#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

// 边结构体
struct Edge {
    int next, to, val;
};

void solve() {
    int n, m;
    cin >> n >> m;

    // 图的邻接表
    vector<int> head(n + 1, 0);
    vector<Edge> ed(N * 2);  // 双向边，预留足够空间
    int cnt = 0;

    auto add_edge = [&](int u, int v, int w) {
        ed[++cnt] = {head[u], v, w};
        head[u] = cnt;
    };

    // 读入边
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add_edge(x, y, z);
        add_edge(y, x, z);
    }

    // BFS 相关变量
    vector<int> q(N), vis(n + 1, 0), val(n + 1, 0);
    vector<int> sz(n + 1, 0);                             // 连通块大小
    vector<vector<int>> bits(n + 1, vector<int>(30, 0));  // 每位的 1 的计数
    vector<int> mor(n + 1, 0);                            // 调整值
    int num = 0;                                          // 连通块计数

    // BFS 函数，使用 lambda 和闭包
    auto bfs = [&](int start, int comp_id) {
        int l = 0, r = 0;
        q[++r] = start;
        vis[start] = comp_id;
        val[start] = 0;

        while (l < r) {
            int u = q[++l];
            sz[comp_id]++;
            for (int i = head[u]; i; i = ed[i].next) {
                int v = ed[i].to;
                int w = ed[i].val;
                if (vis[v]) {
                    if ((val[u] ^ w) != val[v]) {
                        cout << -1 << "\n";
                        exit(0);
                    }
                    continue;
                }
                vis[v] = comp_id;
                val[v] = val[u] ^ w;
                q[++r] = v;
            }
        }
    };

    // 分连通块
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            num++;
            bfs(i, num);
        }
    }

    // 统计每位信息
    for (int i = 1; i <= n; i++) {
        int comp = vis[i];
        for (int j = 0; j < 30; j++) {
            bits[comp][j] += (val[i] >> j) & 1;
        }
    }

    // 计算调整值
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < 30; j++) {
            if (bits[i][j] > sz[i] - bits[i][j]) {
                mor[i] ^= (1 << j);
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << (val[i] ^ mor[vis[i]]) << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t; // 单测，注释掉
    while (t--) {
        solve();
    }
    return 0;
}