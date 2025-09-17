#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tup array<int, 3>
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 1e9;
const int MOD = 998244353;

void solve()
{
    int n, w; // w表示多少列
    cin >> n >> w;
    vector<tup> a1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a1.push_back({x, y, i}); // 需要维持
    }
    sort(a1.begin(), a1.end(), [&](const tup &a, const tup &b)
         { return a[1] < b[1]; });
    vector<vector<pii>> v1(n + 1);
    for (int i = 1; i <= n; i++)
        v1[i] = vector<pii>();
    for (auto h : a1)
    {
        int s = h[0], t = h[1], id = h[2];
        v1[s].push_back({t, id}); // 每一列从小到大排序的每一行数字
    }
    int mn = INF, mx1 = 0;
    for (int i = 1; i <= w; i++)
    {
        mn = min(mn, (int)v1[i].size());
        mx1 = max(mx1, (int)v1[i].size());
    }
    vector<int> ans(n + 1);
    vector<int> mx(n + 1);
    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            mx[j] = max(mx[j], v1[i][j][0]);
        }
    }
    for (int i = mn - 1 + 1; i <= mx1 - 1; i++)
    {
        mx[i] = INF;
    }

    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            int id = v1[i][j][1];
            ans[id] = mx[j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int t, a;
        cin >> t >> a;
        if (ans[a] == INF)
        {
            cout << "Yes\n";
            continue;
        }
        if (t < ans[a])
            cout << "Yes\n";
        else
            cout << "No\n";
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
/*
5 3
1 1
1 2
2 2
3 2
2 3
6
1 1
1 2
2 3
2 5
3 4
3 5
*/