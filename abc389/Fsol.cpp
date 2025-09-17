#include <bits/stdc++.h>
#define int long long // 使用 long long 替代 int，确保大数运算安全
using namespace std;

const int N = 5e5 + 5; // 树状数组的最大值域，题目假设 X, L_i, R_i <= 5e5

int n, q;       // n: 竞赛场数, q: 查询次数
int L[N], R[N]; // L[i]: 第 i 场竞赛的左边界, R[i]: 右边界

// 树状数组实现，用于维护 sum_X（初始评分为 X 的加分总数）
namespace BIT
{
    int tr[N]; // 树状数组，存储差分形式的前缀和

    // 在位置 p 增加值 k，影响 p 及之后的所有 sum_X
    void update(int p, int k)
    {
        for (; p < N; p += p & -p)
            tr[p] += k;
    }

    // 查询从 1 到 p 的前缀和，即 sum_p
    int query(int p)
    {
        int res = 0;
        for (; p; p -= p & -p)
            res += tr[p];
        return res;
    }
}
using namespace BIT;

signed main()
{
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(0);
    cout.tie(0);

    // 输入竞赛场数
    cin >> n;

    // 预处理每场竞赛，确定加分区间并更新 sum_X
    for (int i = 1; i <= n; i++)
    {
        // 输入第 i 场竞赛的评分区间 [L_i, R_i]
        cin >> L[i] >> R[i];
        
        // 二分查找 l_i: 初始评分 X 的最小值，使得 X + sum_X >= L[i]
        int left = 1, right = L[i], l_i = 1; // l_i: 当前竞赛的左边界
        while (left <= right)
        {
            int mid = left + right >> 1; // 中点
            if (mid + query(mid) >= L[i])
            {                    // 若 mid 加分后达到或超过 L[i]
                l_i = mid;       // 更新 l_i
                right = mid - 1; // 尝试更小的 mid
            }
            else
            {
                left = mid + 1; // mid 太小，增大范围
            }
        }

        // 二分查找 r_i: 初始评分 X 的最大值，使得 X + sum_X <= R[i]
        int r_i;                         // 修复：显式声明 r_i
        left = 1, right = R[i], r_i = 1; // r_i: 当前竞赛的右边界
        while (left <= right)
        {
            int mid = left + right >> 1; // 中点
            if (mid + query(mid) <= R[i])
            {                   // 若 mid 加分后不超过 R[i]
                r_i = mid;      // 更新 r_i
                left = mid + 1; // 尝试更大的 mid
            }
            else
            {
                right = mid - 1; // mid 太大，减小范围
            }
        }

        // 更新树状数组：在 [l_i, r_i] 区间内 sum_X 加 1
        update(l_i, 1);      // 从 l_i 开始加 1
        update(r_i + 1, -1); // 在 r_i + 1 减 1，结束加分区间
    }

    // 处理查询
    cin >> q;
    while (q--)
    {
        int X; // 查询的初始评分
        cin >> X;
        // 输出最终评分：初始评分 X + 加分总数 sum_X
        cout << X + query(X) << "\n";
    }

    return 0;
}