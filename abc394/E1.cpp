#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 102;
const int INF = 0x3f3f3f3f;

char a[N][N];
int ans[N][N];
queue<pii> q;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(ans, 0x3f, sizeof(ans));
    // 初始化

    for (int i = 1; i <= n; i++)
    { // 自身到自身
        ans[i][i] = 0;
        q.push({i, i});
    }

    for (int i = 1; i <= n; i++)
    { // 直接相连的路径，一定是回文的，长度=1
        for (int j = 1; j <= n; j++)
        {
            if (i != j && a[i][j] != '-')
            {
                ans[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int i = u.first, j = u.second;

        for (int k = 1; k <= n; k++)
        {
            if (a[k][i] != '-')
            {
                for (int l = 1; l <= n; l++)
                {
                    if (a[k][i] == a[j][l]) // 由于是bfs，首次发现的k-l的回文路径一定是最小的
                    {
                        if (ans[k][l] == INF)
                        {
                            ans[k][l] = ans[i][j] + 2;
                            q.push({k, l});
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] == INF)
                cout << -1 << ' ';
            else
                cout << ans[i][j] << ' ';
        }
        cout << '\n';
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