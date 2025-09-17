#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
树状数组？
区间修改，单点查询
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), c(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        c[i] = a[i] - a[i - (i & -i)];

    auto update = [&](int x, int k)
    {
        while (x <= n)
        {
            c[x] += k;
            x += x & -x;
        }
    };

    auto query = [&](int x)
    {
        int res = 0;
        while (x)
        {
            res += c[x];
            x -= x & -x;
        }
        return res;
    };

    auto out = [&]()
    {
        for (int i = 1; i <= n; i++)
            cout << query(i) << ' ';
        cout << '\n';
    };

    for (int i = 1; i <= n; i++)
    {
        int now = query(i);
        if (now == 0)
            continue;
        int t = min(now, n - i);

        update(i, -t);
        // out();
        update(i + 1, t);
        // out();
        update(i + 1, 1);
        // out();
        update(i + 1 + t - 1 + 1, -1);

        // out();
    }
    out();
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
/*
4
5 0 9 3

*/