#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

struct Query
{
    int r, x, id, ans;
    bool operator<(const Query &other) const { return r < other.r; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 读入并存储查询
    vector<Query> queries(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> queries[i].r >> queries[i].x;
        queries[i].id = i;
    }
    sort(queries.begin() + 1, queries.end()); // 按 r 排序

    // 动态维护 LIS
    vector<int> f(1, 0); // f[0] = 0 作为哨兵
    int qi = 1;          // 当前查询索引
    for (int i = 1; i <= n; i++)
    {
        // 更新 f
        auto it = lower_bound(f.begin(), f.end(), a[i]);
        if (it == f.end())
        {
            f.push_back(a[i]);
        }
        else
        {
            *it = a[i];
        }

        // 处理所有 r == i 的查询
        while (qi <= q && queries[qi].r == i)
        {
            queries[qi].ans = upper_bound(f.begin(), f.end(), queries[qi].x) - f.begin() - 1;
            qi++;
        }
    }

    // 按原始顺序输出
    sort(queries.begin() + 1, queries.end(), [](const Query &a, const Query &b)
         { return a.id < b.id; });
    for (int i = 1; i <= q; i++)
    {
        cout << queries[i].ans << '\n';
    }

    return 0;
}