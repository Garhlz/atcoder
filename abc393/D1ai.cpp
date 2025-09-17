#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    string s = "#", s1;
    cin >> s1;
    s += s1; // 字符串从 1 开始索引

    // 记录所有 1 的位置
    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            pos.push_back(i);
    }
    int m = pos.size();

    // 特判：如果只有 1 个 1，无需操作
    if (m == 1)
    {
        cout << 0 << '\n';
        return;
    }

    // 定义成本函数：计算将所有 1 移动到 [x, x+m-1] 的总交换次数
    auto func = [&](int x) -> ll
    {
        ll ret = 0;
        for (int i = 0; i < m; i++)
        {
            ret += abs(pos[i] - (x + i));
        }
        return ret;
    };

    // 三分法寻找最优左端点
    int l = 1, r = n - m + 1;
    while (r - l >= 3)
    { // 当范围足够大时继续三分
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll fm1 = func(m1), fm2 = func(m2);
        if (fm1 <= fm2) // 并不直接取相等情况，那样会有问题
        {
            r = m2; // 左半部分可能包含最小值
        }
        else
        {
            l = m1; // 右半部分可能包含最小值
        }
    }

    // 在缩小后的范围内枚举最小值
    ll ans = INF;
    for (int i = l; i <= r; i++)
    {
        ans = min(ans, func(i));
    }
    cout << ans << '\n';
}

int main()
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