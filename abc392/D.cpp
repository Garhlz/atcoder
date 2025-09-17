#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[105][100005];
void solve()
{
    int n;
    cin >> n;
    // vector<map<int, int>> a(n + 1, map<int, int>());
    vector<int> cnt(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        cnt[i] = k;
        for (int j = 1; j <= k; j++)
        {
            int t;
            cin >> t;
            mx = max(t, mx);
            a[i][t]++;
        }
    }
    long double ans = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            now = 0;
            for (int k = 1; k <= mx; k++)
            {
                if (a[i][k] == 0 || a[j][k] == 0)
                    continue; // 一定是零
                now += ((long double)a[i][k] / cnt[i]) * ((long double)a[j][k] / cnt[j]);
            }
            ans = max(ans, now);
        }
    }
    cout << fixed << setprecision(15) << ans << '\n';
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
