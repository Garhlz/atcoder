#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
int n, ans[N][N];
char c[N][N];
queue<pair<int, int>> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    
    // 初始化，所有点对的最短回文路径长度为无穷大
    memset(ans, 0x3f, sizeof(ans));
    
    // 处理基础情况1：同一点到自身，路径长度为0（空串是回文）
    for (int i = 1; i <= n; i++)
        ans[i][i] = 0, q.push({ i, i });
    
    // 处理基础情况2：直接相连的点，路径长度为1（单字符是回文）
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && c[i][j] != '-')
                ans[i][j] = 1, q.push({ i, j });
    
    // BFS扩展，利用回文的构造性质
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int i = u.first, j = u.second; // 当前已知的回文路径，从i到j
        
        // 尝试扩展：考虑所有可能的"外层点对"(k,l)
        for (int k = 1; k <= n; k++)
            if (c[k][i] != '-') // 存在从k到i的边
                for (int l = 1; l <= n; l++)
                    if (c[k][i] == c[j][l]) // 边标签相同，可以构成新回文
                        if (ans[k][l] == INF) // 首次发现从k到l的回文路径
                            ans[k][l] = ans[i][j] + 2, q.push({ k, l }); // 更新路径长度并加入队列
    }
    
    // 输出结果
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << (ans[i][j] == INF ? -1 : ans[i][j]) << " \n"[j == n];
    
    return 0;
}