#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

vector<int> v[N];
map<int, int> dp[N];
// 不知道如何开空间，于是用map数组
// dp[i][fa]表示以i为根、fa为父亲的最大子图大小

void dfs(int x, int fa)
{
    if (dp[x][fa] != 0)
    {
        return; // 已经搜过，记忆化
    }

    int need = 3 + (fa == 0);

    vector<int> now;
    for (auto y : v[x])
    {
        if (y != fa)
        {
            dfs(y, x); // 这个儿子的满足条件子树的顶点数
            now.push_back(dp[y][x]);
        }
    }
    // 贪心取最大的方案
    sort(now.begin(), now.end(), greater<int>()); // 降序排序
    if ((long long)now.size() > need)
    {
        now.resize(need); // 只保留需要的几个最大的
        // 如果有父节点，只能算3个
    }

    int sum = 0;
    for (auto i : now)
        sum += i;

    if ((long long)now.size() == need)
    {
        dp[x][fa] = sum + 1; // 自己加上当前最大的子树节点数
    }
    // 这里出了问题，还是ai发现的

    else
        dp[x][fa] = 1; // 只算自己
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int mx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() >= 4)
        { // 中心点，满足至少有一个度数=4的点
            dfs(i, 0);
            mx = max(mx, dp[i][0]);
        }
    }
    cout << mx << '\n';
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
