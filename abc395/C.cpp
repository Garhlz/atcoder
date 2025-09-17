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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> pos;
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        if (pos[a[i]])
        {
            ans = min(ans, i - pos[a[i]] + 1);
        }
        pos[a[i]] = i;
    }
    if (ans == INF)
        cout << -1 << '\n';
    else
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
