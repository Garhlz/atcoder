#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int fa[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m < n - 1)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
        fa[i] = i;

    vector<array<int, 3>> edges(m + 1);
    vector<int> extra; // 多余边，并不一定是重边和自环

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y, i}; // 直接这样存边比较好编号
        int fx = find(x), fy = find(y);
        if (fx == fy)
        { // 已经相连，在同一个连通块中了
            extra.push_back(i);
        }
        else
        {
            fa[fx] = fy;
        }
    }
    vector<int> root;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
            root.push_back(i);
    }

    int cnt = root.size();
    int K = cnt - 1;
    cout << K << '\n';
    if (K == 0)
        return;
    vector<array<int, 3>> ops; // {电缆编号, 原服务器, 新服务器}
    int now = 1;
    for (int i = 0; i < extra.size() && ops.size() < K; i++)
    {
        int id = extra[i];
        auto [x, y, eid] = edges[id];
        int fx = find(x);
        while (now <= n && find(now) == fx)
            now++;
        if (now > n)
            break;
        ops.push_back({eid, x, now});
        fa[fx] = find(now);
    }
    for (auto [idx, from, to] : ops)
    {
        cout << idx << ' ' << from << ' ' << to << '\n';
    }
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
