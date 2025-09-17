#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 1e6 + 10;
// 双层图
/*
关键思路在于把上下翻转视为双层图，即把代价视为两层之间的路径，两层的所有边顺序相反
跑dijkstra即可
*/
struct edge
{
    int to, w, nxt; // 链式前向星
} e[N];

int n, m, x;
int head[N], dis[N], vis[N];
int cnt = 0;

void add(int x, int y, int w)
{
    e[cnt] = {y, w, head[x]};
    head[x] = cnt++; // 从0开始用
}

void dij(int st)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[st] = 0;                                       // {距离，顶点}
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 小根堆

    pq.push({0, st});

    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i != -1; i = e[i].nxt)
        {
            int y = e[i].to, w = e[i].w;
            if (dis[x] + w < dis[y])
            {
                dis[y] = dis[x] + w;
                pq.push({dis[y], y});
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        head[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        add(i, i + n, x);
        add(i + n, i, x);
        // 两层之间的边
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y, 1);
        add(y + n, x + n, 1);
    }
    dij(1);
    cout << min(dis[n], dis[2 * n]) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
