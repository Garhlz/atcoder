#include <bits/stdc++.h>
#define int long long // 保留原定义，方便处理大数
using namespace std;

const int N = 20;           // 定义数组大小常量，题目保证 N <= 12
int n;                      // 袋子数量
int a[N];                   // 初始石子数数组
int b[N];                   // 当前每个袋子的石子数
int ans;                    // 不同异或值的数量
unordered_map<int, int> mm; // 记录出现过的异或值，键为异或值，值为标记

// DFS 函数：枚举石子分配方式
// x: 当前处理的石子编号（1 到 n）
// m: 当前使用的袋子数量（0 到 n-1）
void dfs(int x, int m)
{
    // 所有石子分配完成
    if (x == n + 1)
    {
        int x_or = 0; // 当前所有袋子的异或值
        for (int i = 1; i <= m; i++)
        {
            x_or ^= b[i]; // 计算异或值
        }
        if (!mm.count(x_or))
        {                 // 如果异或值未出现过
            mm[x_or] = 1; // 标记为已出现
            ans++;        // 计数加 1
        }
        return;
    }

    // 选择 1：将当前石子放入已有袋子
    for (int i = 1; i <= m; i++)
    {
        b[i] += a[x];  // 将石子 a[x] 加入袋子 i
        dfs(x + 1, m); // 递归处理下一个石子，袋子数不变
        b[i] -= a[x];  // 回溯，恢复袋子 i 的状态
    }

    // 选择 2：将当前石子放入新袋子
    b[m + 1] = a[x];   // 新袋子 m+1 存储当前石子
    dfs(x + 1, m + 1); // 递归处理下一个石子，袋子数加 1
    // 无需显式回溯 b[m+1]，会被下次覆盖
}

signed main()
{
    cin >> n; // 输入袋子数量
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // 输入每个袋子的初始石子数
    }
    ans = 0;     // 初始化答案
    dfs(1, 0);   // 从第 1 个石子开始，初始袋子数为 0
    cout << ans; // 输出不同异或值的数量
    return 0;
}