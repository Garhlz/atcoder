#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = '#' + a[i];
    }
    int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '#')
            {
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }
    int flag = 1;
    for (int i = mnx; i <= mxx; i++)
    {
        for (int j = mny; j <= mxy; j++)
        {
            if (a[i][j] == '.')
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
        cout << "Yes\n";
    else
        cout << "No\n";
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
