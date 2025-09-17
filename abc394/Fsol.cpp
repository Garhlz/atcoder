#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
vector<int> a[N];    // 邻接表
map<int, int> dp[N]; // dp[i][fa]表示以i为根、fa为父亲的最大子图大小

void dfs(int u, int fa)
{
    // 记忆化搜索
    if (dp[u][fa] != 0)
        return;

    // 确定需要的子树数：根节点需要4个，非根需要3个
    int need = 3 + (fa == 0);

    // 存储所有子树的dp值
    vector<int> ls;
    for (auto i : a[u])
    {
        if (i != fa) // 不往父节点走
        {
            dfs(i, u);              // 递归处理子树
            ls.push_back(dp[i][u]); // 记录子树的dp值
        }
    }

    // 按dp值从大到小排序，只保留前need大的值
    sort(ls.begin(), ls.end(), greater<int>());
    if ((long long)ls.size() > need)
        ls.resize(need); // 只保留前need个最大值

    // 计算dp值：如果能恰好选need个子树，则累加这些子树的dp值；否则为0
    int sum = 0;
    for (auto i : ls)
        sum += i;

    // 最终dp值 = 子树贡献 + 当前节点(1)
    dp[u][fa] = ((long long)ls.size() == need ? sum : 0) + 1;
}

int main()
{
    int n;
    cin >> n;

    // 建图
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    // 枚举所有可能的中心点（度数≥4的顶点）
    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].size() >= 4) // 只有度数≥4的点才可能是中心
        {
            dfs(i, 0);                  // 以i为根，0表示没有父节点
            maxn = max(maxn, dp[i][0]); // 更新最大值
        }
    }

    cout << maxn;
    return 0;
}