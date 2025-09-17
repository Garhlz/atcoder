#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s = "#", s1;
    cin >> s1;
    s += s1;
    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            pos.push_back(i);
    }
    int m = pos.size();
    if (m == 1)
    {
        cout << 0 << '\n';
        return;
    }
    int l = 1, r = n - m + 1;
    function<int(int)> func = [&](int x) { // 输入左端点坐标
        int ret = 0;
        int now = 0;
        for (int i = x; i <= x + m - 1; i++)
        {
            ret += abs(pos[now] - i);
            now++;
        }
        return ret;
    };
    // 使用三分法，因为是单峰函数
    while (r - l > 2)
    {
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        int p = func(m1), q = func(m2);
        if (p < q)
        {
            r = m2;
        }
        else if (p > q)
        {
            l = m1;
        }
        else
        {
            l = m1, r = m2;
        }
    }
    int ans = INF;
    for (int i = l; i <= r; i++)
    {
        ans = min(ans, func(i));
    }
    cout << ans << '\n';
}

/*
10
0101001001
2 4 7 10
5 3 1 2 5
*/
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
