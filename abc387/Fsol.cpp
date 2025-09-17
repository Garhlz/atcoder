#include <bits/stdc++.h>
using namespace std;

const int N = 2030;              // 最大节点数（题目中 N 最大 2000 左右）
const int P = 998244353;         // 模数，用于结果取模
int n, m, ans;                   // n: 序列长度, m: 数值上限, ans: 最终答案
int f[N][N];                     // DP 数组: f[u][i] 表示以 u 为根，x_u <= i 的方案数
bool st[N], vis[N];              // st[u]: u 是否有入度（用于找根）, vis[u]: Tarjan 中是否在栈中
int low[N], dfn[N], bl[N];       // Tarjan 用: dfn[u] 时间戳, low[u] 最早可达时间, bl[u] SCC 编号
int dfi, cnt;                    // dfi: 时间戳计数器, cnt: SCC 数量
int h[N], e[N], ne[N], idx = 1;  // 新图邻接表: h[u] 起点, e[i] 终点, ne[i] 下一条边, idx 边计数
vector<int> g[N];                // 原图: g[u] 存储 u 的出边
stack<int> stk;                  // Tarjan 用栈，存储当前路径上的节点

// 快速读入函数（优化输入效率）
inline int read() {
    int x = 0, f = 1;             // x: 读入的数, f: 符号（1 正，-1 负）
    char c = getchar();           // 读取一个字符
    while (!isdigit(c)) {         // 跳过非数字字符
        f = (c == '-' ? -1 : 1);  // 处理负号
        c = getchar();
    }
    while (isdigit(c)) {                     // 处理数字部分
        x = (x << 3) + (x << 1) + (c ^ 48);  // x = x*10 + (c-'0')
        c = getchar();
    }
    return x * f;  // 返回结果
}

// 添加有向边到新图（缩点后的图）
void add(int a, int b) {
    e[idx] = b;      // 边的终点是 b
    ne[idx] = h[a];  // 下一条边的索引（链表结构）
    h[a] = idx++;    // 更新起点的边索引，并递增 idx
}

// Tarjan 算法：找出强连通分量（SCC）
void tarjan(int x) {
    dfn[x] = low[x] = ++dfi;               // 初始化：访问时间和最早可达时间相同
    stk.push(x);                           // 将当前节点压入栈
    vis[x] = 1;                            // 标记 x 在栈中
    for (int y : g[x]) {                   // 遍历 x 的所有邻接点 y（原图中的出边）
        if (!dfn[y]) {                     // 如果 y 未被访问
            tarjan(y);                     // 递归访问 y
            low[x] = min(low[x], low[y]);  // 更新 x 的最早可达时间
        } else if (vis[y]) {               // 如果 y 已访问且在栈中
            low[x] = min(low[x], dfn[y]);  // 用 y 的访问时间更新 x
        }
    }
    if (dfn[x] == low[x]) {       // 如果 x 是 SCC 的起点（无法回溯更早）
        cnt++;                    // 新增一个 SCC
        while (stk.top() != x) {  // 将栈中节点弹出，直到 x
            int u = stk.top();
            stk.pop();
            bl[u] = cnt;  // 标记 u 属于当前 SCC
            vis[u] = 0;   // u 离开栈
        }
        bl[x] = cnt;  // x 也属于当前 SCC
        vis[x] = 0;   // x 离开栈
        stk.pop();
    }
}

// DFS 计算 DP 值（树形 DP）
void dfs(int u) {
    // 遍历 u 的所有子节点（新图中的出边）
    for (int i = h[u]; i; i = ne[i]) {
        int v = e[i];  // 子节点 v
        dfs(v);        // 先递归计算 v 的 DP 值
        for (int j = 1; j <= m; j++) {
            // 对于每个可能的 x_u = j，乘上 v 的方案数
            f[u][j] = 1ll * f[u][j] * f[v][j] % P;
            // f[u][j] 原为 x_u = j 的方案数，f[v][j] 是 x_v <= j 的方案数
        }
    }
    // 将 f[u][i] 从 “x_u = i” 调整为 “x_u <= i”
    for (int i = 2; i <= m; i++) {
        f[u][i] = (f[u][i] + f[u][i - 1]) % P;
        // 累加前缀和：包含 x_u = 1 到 i 的所有情况
    }
}

int main() {
    n = read();
    m = read();  // 读入 n 和 m
    // 读入 A 数组并建图，同时初始化 DP 数组
    for (int i = 1; i <= n; i++) {
        int a = read();     // A[i]
        g[a].push_back(i);  // 从 A[i] 到 i 加边
        for (int j = 1; j <= m; j++) {
            f[i][j] = 1;  // 初始化：每个节点单独时方案数为 1
        }
    }
    // 对所有节点运行 Tarjan，找出 SCC
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {  // 未访问的节点
            tarjan(i);
        }
    }
    // 构建缩点后的新图
    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {               // 遍历原图的边 i -> j
            if (bl[i] == bl[j]) continue;  // 如果 i 和 j 在同一 SCC，跳过
            add(bl[i], bl[j]);             // 在新图中加边：SCC(i) -> SCC(j)
            st[bl[j]] = 1;                 // 标记 SCC(j) 有入度
        }
    }
    ans = 1;  // 初始化答案为 1（乘法单位）
    // 对每个无入度的 SCC（树的根）计算 DP
    for (int i = 1; i <= cnt; i++) {
        if (!st[i]) {                       // 如果 i 是根节点
            dfs(i);                         // 计算以 i 为根的子树方案数
            ans = 1ll * ans * f[i][m] % P;  // 乘上 x_i <= m 的方案数
        }
    }
    printf("%d\n", ans);  // 输出最终答案
    return 0;
}