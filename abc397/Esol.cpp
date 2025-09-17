#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 10;

int n, k, c[MAXN];
vector<int> p[MAXN];

void dfs(int u, int ufa) {
    unordered_map<int, int> d;  // 记录子树中未完成路径的长度及其数量
    int now;
    d[0] = INT_MAX;  // 初始化 d[0] 为无穷大，表示已完成路径不限制
    bool op = 0;     // 是否已通过 u 连接两条路径

    for (auto v : p[u]) {
        if (v != ufa) {
            dfs(v, u);  // 递归处理子节点
            now = c[v];
            if (now == k || now == 0) continue;  // 已完成或无路径，跳过

            if (d.count(k - now - 1) && d[k - now - 1] > 0) {
                if (op) {
                    cout << "No";
                    exit(0);
                }                  // 已连接过一次，无解
                --d[k - now - 1];  // 匹配成功，减少一条路径
                op = 1;            // 标记 u 已使用
            } else {
                ++d[now];  // 未匹配，记录该长度
            }
        }
    }

    int res = 0;  // 剩余未完成路径的长度
    for (auto [i, j] : d) {
        if (i > 0 && j > 0) {  // 存在未完成路径
            if (res) {
                cout << "No";
                exit(0);
            }  // 多于一条未完成路径，无解
            if (op) {
                cout << "No";
                exit(0);
            }         // 已连接过，剩余路径无解
            res = i;  // 记录唯一未完成路径长度
        }
    }

    c[u] = res + (!op);  // 更新 c[u]：若未连接，长度加 1
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n * k; i++) {
        int u, v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    if (k == 1) {
        cout << "Yes";
        return 0;
    }  // 特判 k=1

    dfs(1, 0);
    cout << ((c[1] == k || c[1] == 0) ? "Yes" : "No");

    return 0;
}