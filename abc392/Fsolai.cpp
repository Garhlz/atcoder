#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5 + 10; // 最大数组长度

// 线段树结构体
struct SegTree
{
    vector<int> tr; // 线段树数组，记录区间未赋值位置数

    SegTree(int n) : tr(n * 4, 0) {} // 初始化线段树大小

    // 建树：初始化每个位置为未赋值（1）
    void build(int node, int left, int right)
    {
        if (left == right)
        {
            tr[node] = 1; // 叶节点表示单个位置，初始未赋值
            return;
        }
        int mid = (left + right) >> 1;
        build(node << 1, left, mid);                  // 左子树
        build(node << 1 | 1, mid + 1, right);         // 右子树
        tr[node] = tr[node << 1] + tr[node << 1 | 1]; // 更新父节点
    }

    // 单点更新：将位置 x 标记为已赋值
    void update(int node, int left, int right, int x)
    {
        if (left == right)
        {
            tr[node]--; // 未赋值位置数减 1
            return;
        }
        int mid = (left + right) >> 1;
        if (x <= mid)
            update(node << 1, left, mid, x);
        else
            update(node << 1 | 1, mid + 1, right, x);
        tr[node] = tr[node << 1] + tr[node << 1 | 1]; // 更新父节点
    }

    // 查询第 k 个未赋值位置
    int query(int node, int left, int right, int k)
    {
        if (left == right)
            return left; // 找到叶节点
        int mid = (left + right) >> 1;
        if (tr[node << 1] < k) // 左子树未赋值位置不足 k 个
            return query(node << 1 | 1, mid + 1, right, k - tr[node << 1]);
        return query(node << 1, left, mid, k); // 在左子树中查找
    }
};

int main()
{
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> pos(n + 1); // 插入位置 P_i，从 1 开始
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
    }

    vector<int> result(n + 1); // 最终数组 A
    SegTree seg(n);            // 创建线段树
    seg.build(1, 1, n);        // 初始化线段树

    // 从后向前插入
    for (int i = n; i >= 1; i--)
    {
        int idx = seg.query(1, 1, n, pos[i]); // 查询第 P_i 个未赋值位置
        result[idx] = i;                      // 在该位置插入 i
        seg.update(1, 1, n, idx);             // 更新该位置为已赋值
    }

    // 输出最终数组
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << (i < n ? " " : "\n"); // 最后一个数后换行
    }

    return 0;
}