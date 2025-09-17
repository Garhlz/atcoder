#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 1e6 + 10;
/*
思路类似筛法，和数的范围高度相关，记录倍数的数量
如果当前倍数数量达标，更新所有倍数的ans为当前值，从小到大枚举筛选，
*/
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), vis(N, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[a[i]]++;
    }
    vector<int> ans(N, 0);
    int mx = *max_element(a.begin() + 1, a.end());
    // 找到最大 ai

    for (int x = 1; x <= mx; x++)
    {
        int sum = 0;
        for (int j = x; j <= mx; j += x)
        { // 所有倍数的数量之和
            // 范围是数字上限，而不是数组
            sum += vis[j];
        }
        if (sum >= k) // 如果倍数的数量可以达到k，就更新所有的gcd
        {
            for (int j = x; j <= mx; j += x)
            {
                ans[j] = max(ans[j], x);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[a[i]] << '\n';
    }
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
