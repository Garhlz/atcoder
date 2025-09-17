#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
实际上是二分加贪心
*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = m;
    // 二分的是购买的最贵的商品价格
    auto chk = [&](int x)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int k = (x + a[i]) / (2 * a[i]); // 找到当前上限，当前商品，最大购买量
            if (k > 1e9 || a[i] > 2e18 / (k * k))
                return 0;
            int now = k * k * a[i]; // 可以直接算出当前商品的总价格
            if (now + cnt > m)      // 看是否超过了预算
                return 0;
            cnt += now;
        }
        return 1;
    };

    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (chk(m))
            l = m;
        else
            r = m;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = (l + a[i]) / (2 * a[i]);
        m -= now * now * a[i]; // now表示最大的k
        ans += now;
    }
    ans += m / (l + 1); // 剩下的用来尝试购买价格为k+1的商品
    // 根据二分，可以买完价格在 l 及以下的所有物品，而 l+1 不能，有多的物品买不起，而不会出现买完了的情况
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
