#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
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
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        a[i] += pq.size();
        while (!pq.empty() && pq.top() <= i) // 已经贡献过了，也要弹出，所以取等
        {
            pq.pop();
        }
        if (a[i])
        {
            pq.push(i + a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int now = max(0ll, a[i] - (n - i));
        cout << now << ' ';
    }
    cout << '\n';
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