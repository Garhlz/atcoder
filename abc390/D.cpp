#include <bits/stdc++.h>
using namespace std;
#define int long long
// 注意开ll
/*
- 观察到N<=12，考虑暴力搜索，剪枝
- 问题转化为把 n 个数字填充到 n 个袋子中，求最后的异或和数量
- 对于每个数字i，只讨论1-i的袋子，因为填充是任意的，减少讨论数量
- 还有一点，对于每个数字i，限制为只可以填充第一个空袋子，因为空袋子都是等价的，这样可以剪枝
- 如此暴力搜索，用unordered_map存放最后的异或和，否则可能会超时
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(20), b(20);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    unordered_map<int, int> mp;
    function<void(int, int)> dfs = [&](int x, int m) { // m表示已经分配过的袋子数量
        if (x == n + 1)
        {
            int now = 0;
            for (int i = 1; i <= m; i++)
            {
                now ^= b[i];
            }
            if (!mp.count(now))
            {
                mp[now] = 1;
                ans++;
            }
            return;
        }
        
        for (int i = 1; i <= m; i++)
        {
            b[i] += a[x];  // 注意这里加的东西是什么...
            dfs(x + 1, m); // 已经填充的袋子数量不变，不需要讨论更多的空间
            // 一个剪枝
            b[i] -= a[x];
        }

        b[m + 1] = a[x];
        dfs(x + 1, m + 1);
    };
    dfs(1, 0);
    cout << ans << '\n';
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
