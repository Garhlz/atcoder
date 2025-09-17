#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define tup array<int, 3>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

// dp[i][x][3] 表示前i个，消耗x卡路里，获得的vi维他命最多是多少

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<tup> p(n + 1);

    vector<tup> dp(x + 1);
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
        for (int j = x-c; j >= 0; j--)
        {
            dp[j + c][v] = max(dp[j + c][v], dp[j][v] + a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        int now = min(dp[i][0], min(dp[i][1], dp[i][2]));
        ans = max(ans, now);
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
