#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define tup array<int, 3>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

// dp[i][x][3] 表示前i个，消耗x卡路里，获得的vi维他命最多是多少
/*
- 对于每一种维他命，单独计算消耗，由此进行01背包
- 01背包可以优化掉第一维的dp数组，原理是从后往前继承更新不会对这一轮造成额外影响
- 最后枚举每个种类的维他命占据的消耗，枚举$O(n^2)$即可，取其中三者最小值的最大值
*/

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<tup> p(n + 1);

    vector<vector<int>> dp(x + 1, vector<int>(3)); // 分别零一背包，表示的消耗是各自的消耗而不是消耗之和
    for (int i = 1; i <= n; i++)
    {
        int v, a, c;
        cin >> v >> a >> c;
        v--;
        p[i] = {v, a, c};
    }

    for (int i = 1; i <= n; i++)
    {
        auto [v, a, c] = p[i];
        for (int j = x - c; j >= 0; j--)
        {
            dp[j + c][v] = max(dp[j + c][v], dp[j][v] + a);
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; i + j <= x; j++)
        {
            int k = x - i - j;
            int now = min(dp[i][0], min(dp[j][1], dp[k][2]));
            ans = max(ans, now);
        }
    }
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
