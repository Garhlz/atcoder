#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        int j = n + 1 - i;
        if (i > j)
            break;
        for (int p = min(i, j); p <= max(i, j); p++)
        {
            for (int q = min(i, j); q <= max(i, j); q++)
            {
                if (i & 1)
                    a[p][q] = '#';
                else
                    a[p][q] = '.';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
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
