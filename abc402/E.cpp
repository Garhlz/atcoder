#include <bits/stdc++.h>  // 引入万能头文件

using namespace std;
const int N = 10, M = 1 << 8, K = 5005;
int n, m;
int s[N], c[N];
double p[N], f[K][M];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> c[i];
        double pp;
        cin >> pp;
        p[i] = pp / 100;
    }

    // DP过程
    // f数组会被全局初始化为0.0，f[0][0]=0是正确的初始状态（花费0，没解决题目，期望得分0）

    // 循环遍历所有可能的已解决题目集合 i (mask)
    // i 从 1 开始，表示至少解决了一道题。f[k][0] (花费k，解决0题) 的情况，如果s[j]都大于0，则通常为0。
    for (int i = 1; i < (1 << n); i++) {  // i 是当前的解题集合 mask
        // 循环遍历集合 i 中的每一道题目 j
        // j 被看作是“达成集合 i”或者“维持集合 i”时，最后一次被尝试的题目
        for (int j = 1; j <= n; j++) {
            // 检查题目 j 是否真的在集合 i 中
            if (!((i >> (j - 1)) & 1)) {  // (j-1) 是因为题目编号1到n，但位运算是0到n-1
                continue;                 // 如果j不在集合i中，则跳过
            }
            // 循环遍历总花费 k
            // k 必须至少为 c[j]，因为我们假设最后一次操作是尝试题目j，花费了c[j]
            for (int k = c[j]; k <= m; k++) {
                // 状态转移方程的应用
                // f[k][i] 的当前值 vs 通过尝试题目j得到状态(k,i)的期望值
                f[k][i] = max(f[k][i],                                           // 取当前已知的f[k][i]和新计算的较大值
                              (f[k - c[j]][i ^ (1 << (j - 1))] + s[j]) * p[j] +  // 情况1: 尝试j成功
                                  f[k - c[j]][i] * (1 - p[j])  // 情况2: 尝试j失败 (但j已在i中，是之前解出的)
                );
            }
        }
    }

    // printf("%.10lf\n", f[m][(1 << n) - 1]);
    cout << fixed << setprecision(10) << f[m][(1 << n) - 1] << '\n';
    return 0;
}