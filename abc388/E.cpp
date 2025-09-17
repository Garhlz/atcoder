#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
第一个越大，第二个越小，就越难获取
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(all(a));

    // pair<较大值, 较小值>，小顶堆
    priority_queue<pii, vector<pii>, greater<pii>> q1;
    // 小根堆, 表示没有用到的
    priority_queue<int, vector<int>, greater<int>> q2;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int now = a[i];
        if (!q2.empty() && q2.top() * 2 <= now)
        {
            q1.push({now, q2.top()});
            q2.pop();
        }
        else if (!q1.empty() && q1.top().first < a[i])
        {
            auto [big, small] = q1.top();
            q1.pop();
            q2.push(big);
            q1.push({a[i], small});
        }
        else
            q2.push(a[i]);
    }
    cout << q1.size() << '\n';
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
