#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int b[405];                           // 存储 10^k % M
int ans;                              // 最终答案
int d[25][25];                        // 输入的原始网格
int a[25][25];                        // 预计算的贡献
vector<vector<vector<long long>>> c;  // c[0][i] 和 c[1][i] 存储路径贡献

// DFS 函数：i 表示搜索方向（0 为从 (1,1) 开始，1 为从 (n,n) 开始）
inline void dfs(int i, int x, int y, int s) {
    if (x + y == n + 1) {              // 到达对角线
        if (i) s = (s + a[x][y]) % m;  // 如果是从 (n,n) 来的，包含对角线点的贡献
        c[i][x].emplace_back(s);       // 动态添加路径贡献
        return;
    }
    s = (s + a[x][y]) % m;  // 累加当前格子的贡献
    if (i) {                // 从 (n,n) 开始，向上或向左
        if (x > 1) dfs(i, x - 1, y, s);
        if (y > 1) dfs(i, x, y - 1, s);
    } else {  // 从 (1,1) 开始，向下或向右
        if (x < n) dfs(i, x + 1, y, s);
        if (y < n) dfs(i, x, y + 1, s);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    c.resize(2, vector<vector<long long>>(n + 1));  // 初始化 c 数组
    int N = 2 * n - 1;
    b[1] = 1;
    for (int i = 2; i <= N; i++) b[i] = (b[i - 1] * 10) % m;  // 预计算 10^k % M
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            a[i][j] = ((d[i][j] % m) * (b[N - i - j + 2] % m)) % m;  // 预计算贡献
        }
    dfs(0, 1, 1, 0);                // 从 (1,1) 开始
    dfs(1, n, n, 0);                // 从 (n,n) 开始
    for (int i = 1; i <= n; i++) {  // 对每个对角线点排序
        sort(c[0][i].begin(), c[0][i].end());
        sort(c[1][i].begin(), c[1][i].end());
    }
    for (int i = 1; i <= n; i++) {   // 合并答案
        int k = c[1][i].size() - 1;  // 指向 c[1][i] 的最大值
        for (int j = 0; j < c[0][i].size(); j++) {
            if (k >= 0) ans = max(ans, (c[0][i][j] + c[1][i][k]) % m);  // 尝试 x + y_max
            while (k >= 0 && c[0][i][j] + c[1][i][k] >= m) k--;         // 找到第一个 x + y < M
            if (k >= 0) ans = max(ans, (c[0][i][j] + c[1][i][k]) % m);  // 更新答案
        }
    }
    cout << ans;
    return 0;
}