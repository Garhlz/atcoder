#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

/*
4 3 1 2 3 3 3 4
是单向的，可以从左侧取到右侧的相同数字，但是不能从右侧取到左侧的
恰好不重不漏，如果nxt[i] = min(pos[a[i] + 1], pos[a[i]]);就错误了
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), nxt(n + 1);
    vector<int> pos(N, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        pre[i] = max(pos[a[i]], pos[a[i] + 1]);
        pos[a[i]] = i;
    }

    fill(all(pos), n + 1);
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = pos[a[i] + 1];
        pos[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (nxt[i] - i) * (i - pre[i]);
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