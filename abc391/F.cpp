#include <bits/stdc++.h>
using namespace std;

#define int long long
#define st array<int, 4>

priority_queue<st> pq; // 记住是默认大根堆

void solve()
{
    int n, K;
    cin >> n >> K;
    vector<int> a(n), b(n), c(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    auto func = [&](int i, int j, int k)
    {
        return a[i] * b[j] + a[i] * c[k] + b[j] * c[k];
    };

    pq.push({func(0, 0, 0), 0, 0, 0});
    int now = 0;
    int ans = 0;
    map<st, int> vis;
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        if (!vis[x])
        {
            vis[x] = 1;
            now++;
        } // 是数对访问不可以重复，而不是答案不可以重复
        // 这里的bfs显然会多次经过同一个数对位置
        else
            continue;

        if (now == K)
        {
            ans = x[0];
            break;
        }
        if (x[1] < n - 1)
            pq.push({func(x[1] + 1, x[2], x[3]), x[1] + 1, x[2], x[3]});
        if (x[2] < n - 1)
            pq.push({func(x[1], x[2] + 1, x[3]), x[1], x[2] + 1, x[3]});
        if (x[3] < n - 1)
            pq.push({func(x[1], x[2], x[3] + 1), x[1], x[2], x[3] + 1});
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
