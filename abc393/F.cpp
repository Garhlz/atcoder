#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10;

struct Query
{
    int r, x, id, ans;
    bool operator<(const Query &other) const
    {
        return r < other.r;
    }
};

/*
离线，根据查询的前缀边界排序即可
可以直接在LIS的贪心插入的单调队列中二分查找每个查询的数值限制位置
因为构造单调队列的时候已经贪心取得最小值了，直接二分限制位置已经可以得知可以取得的数量
*/

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<Query> query(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].r >> query[i].x;
        query[i].id = i; // 离线处理，所以需要记录原始顺序
    }

    sort(query.begin() + 1, query.end());

    vector<int> f(1, 0);
    int qi = 1;
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(f.begin(), f.end(), a[i]);
        if (it == f.end())
            f.push_back(a[i]);
        else
            *it = a[i];

        while (qi <= q && query[qi].r == i)
        { // 处理恰好卡到这里的查询
            int now = upper_bound(f.begin(), f.end(), query[qi].x) - f.begin() - 1;
            query[qi++].ans = now;
        }
    }

    sort(query.begin() + 1, query.end(), [](const Query &a, const Query &b)
         { return a.id < b.id; });
    for (int i = 1; i <= q; i++)
    {
        cout << query[i].ans << '\n';
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
