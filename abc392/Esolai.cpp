#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 10;

int fa[MAX_N];

// 并查集查找，带完整路径压缩
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]); // 实时压缩路径
    return fa[x];
}

// 并查集合并
void unite(int x, int y)
{
    fa[find(x)] = find(y); // 合并两连通分量
}

int main()
{
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 检查无解情况：边数不足以连通
    if (m < n - 1)
    {
        cout << "-1\n";
        return 0;
    }

    // 初始化并查集
    for (int i = 1; i <= n; i++)
        fa[i] = i;

    // 记录电缆和多余边
    vector<tuple<int, int, int>> edges(m + 1); // {x, y, idx}
    vector<int> extra;                         // 多余边编号
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y, i};
        int fx = find(x), fy = find(y);
        if (fx == fy)
        {
            extra.push_back(i); // 记录重边,自环或成环边
        }
        else
        {
            unite(x, y); // 合并连通分量
        }
    }

    // 统计连通分量
    int cnt = 0;
    vector<int> roots; // 连通分量根节点
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            cnt++;
            roots.push_back(i);
        }
    }
    int K = cnt - 1; // 最小操作次数
    cout << K << '\n';

    // 若已连通，无需操作
    if (K == 0)
        return 0;

    // 构造操作序列
    vector<tuple<int, int, int>> ops; // {电缆编号, 原服务器, 新服务器}
    int k = 1;                        // 当前扫描的服务器
    for (int i = 0; i < extra.size() && ops.size() < K; i++)
    {
        int idx = extra[i];
        auto [x, y, edge_idx] = edges[idx];
        int fx = find(x); // 当前边的连通分量
        // 找到第一个未连通的服务器
        while (k <= n && find(k) == fx)
            k++;
        if (k > n)
            break; // 无可用服务器
        ops.push_back({edge_idx, x, k});
        unite(k, x); // 合并连通分量
    }

    // 输出操作序列
    for (auto [idx, from, to] : ops)
    {
        cout << idx << ' ' << from << ' ' << to << '\n';
    }

    return 0;
}