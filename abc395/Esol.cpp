#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 1e6 + 5; // 最大顶点数，考虑双层图后为 2N

// 边结构体：存储起点、终点、权重和下一条边的索引
struct Edge
{
    ll to, weight, next;
};

// 全局变量
ll n, m, x;          // 顶点数、边数、翻转成本
ll head[MAX_N];      // 邻接表头数组
ll dist[MAX_N];      // 最短距离数组
bool visited[MAX_N]; // 访问标记数组
Edge edges[MAX_N];   // 边数组
ll edge_cnt = 0;     // 边计数器

// 添加一条边到邻接表
void add_edge(ll from, ll to, ll weight)
{
    edges[edge_cnt] = {to, weight, head[from]};
    head[from] = edge_cnt++;
}

// Dijkstra 算法：计算从起点 st 到所有顶点的最短距离
void dijkstra(ll st)
{
    // 初始化距离数组为无穷大
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, false, sizeof(visited));
    dist[st] = 0;

    // 定义优先队列节点：顶点和当前距离
    using Node = pair<ll, ll>; // {距离, 顶点}
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(0, st);

    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue; // 已访问的顶点跳过
        visited[u] = true;

        // 遍历 u 的所有出边
        for (ll i = head[u]; i != -1; i = edges[i].next)
        {
            ll v = edges[i].to;
            ll w = edges[i].weight;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main()
{
    // 加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 初始化邻接表
    memset(head, -1, sizeof(head));

    // 读入顶点数、边数和翻转成本
    cin >> n >> m >> x;

    // 构建双层图
    // 1. 层间边：连接原始层和反转层，成本为 X
    for (ll i = 1; i <= n; i++)
    {
        add_edge(i, i + n, x); // 从原始层到反转层
        add_edge(i + n, i, x); // 从反转层到原始层
    }

    // 2. 输入边：原始图和反转图的边，成本为 1
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        add_edge(u, v, 1);         // 原始图的正向边
        add_edge(v + n, u + n, 1); // 反转图的反向边
    }

    // 从顶点 1 开始运行 Dijkstra
    dijkstra(1);

    // 输出最小成本：到达原始层 N 或反转层 N 的较小值
    cout << min(dist[n], dist[2 * n]) << "\n";

    return 0;
}