#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
通过引入"坐标"的新一层抽象，简化了问题
鸽子移动到巢->鸽子移动到另一个坐标
两个巢穴中的所有鸽子互换位置->两个巢穴交换，鸽子不动，但是鸽子->位置->巢穴的映射改变了
*/
void solve()
{
    int n, q;
    cin >> n >> q;
    // 定义三个数组：
    // st[i]：巢 i 当前的坐标位置
    // ed[i]：坐标位置 i 当前对应的巢编号
    // home[i]：鸽子 i 当前所在的坐标位置
    vector<int> st(n + 1), ed(n + 1), home(n + 1);

    for (int i = 1; i <= n; i++)
    {
        st[i] = ed[i] = home[i] = i;
    }

    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b;
            cin >> a >> b;
            home[a] = st[b];
            // 分离了鸽子和巢，用坐标连接起来表示
        }
        else if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            ed[st[a]] = b; // 原先巢 a 的坐标现在对应巢 b
            ed[st[b]] = a; // 原先巢 b 的坐标现在对应巢 a
            // 交换巢 a 和巢 b 的坐标位置
            swap(st[a], st[b]);
        }
        else
        {
            int a;
            cin >> a;
            cout << ed[home[a]] << '\n';
        }
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
