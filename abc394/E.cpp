#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int INF = 1e9;
struct p
{
    char c;
    int to;
};
int n;
vector<p> a[N];
int vis[N];
map<pair<int, int>, vector<string>> mp;
vector<vector<int>> ans;
string str;

int pal(string &s)
{
    string tmp = s;
    reverse(s.begin(), s.end());
    if (s == tmp)
    {
        return 1;
    }
    else
    {
        s = tmp;
        return 0;
    }
}

void dfs(int st, int x)
{
    for (auto [c, y] : a[x])
    {

        if (vis[y] && x != y)
            continue;
        if (vis[y] == n * n)
            continue;
        if (str.size() > ans[st][y] + 2)
            continue;

        vis[y]++;
        str.push_back(c);
        mp[{st, y}].push_back(str);

        if (pal(str))
        {
            ans[st][y] = min(ans[st][y], (int)str.size());
        }

        dfs(st, y);

        vis[y]--;
        str.pop_back();
    }
}

void out(int i, int j)
{
    cout << i << ' ' << j << ":\n";
    for (auto ss : mp[{i, j}])
    {
        cout << ss << ' ';
    }
    cout << '\n';
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c != '-')
            {
                a[i].push_back({c, j});
            }
        }
    }

    ans = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mp[{i, j}] = vector<string>();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        str = "";

        for (auto [c, y] : a[i])
        {
            vis[y] = 1;
            str.push_back(c);
            mp[{i, y}].push_back(str);

            dfs(i, y);

            vis[y] = 0;
            str.pop_back();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << 0 << ' ';
                continue;
            }
            int mn = 1e9;
            if (!mp[{i, j}].empty())
            {
                for (auto ss : mp[{i, j}])
                {
                    string tmp = ss;
                    reverse(ss.begin(), ss.end());
                    if (tmp == ss)
                    {
                        mn = min(mn, (int)ss.size());
                    }
                }
            }

            // out(i, j);

            if (mn == 1e9)
            {
                mn = -1;
            }
            cout << mn << ' ';
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
