#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int u[N], d[N];
int n, x;
// 当成二分答案比较好
/*
对于一个位置的两颗牙齿，自身的长度只能缩小。因此可以得到：
int l1 = max(0ll, h - d[i]);
int r1 = min(u[i], h);

而当前牙齿的长度范围需要和上一颗牙齿的范围扩大之后（贪心，利用绝对值差<=x）的范围取交集
集合不断更新，需要中间有可取的数值
*/
int chk(int h)
{
    int l = max(0ll, h - d[1]);
    int r = min(u[1], h);
    if (l > r)
        return 0;
    // 第一颗上牙的范围
    for (int i = 2; i <= n; i++)
    {
        int l1 = max(0ll, h - d[i]);
        int r1 = min(u[i], h);
        // l2,r2是考虑到了相邻上牙之差限制的范围
        int l2 = max(l1, l - x);
        int r2 = min(r1, r + x);
        // 和上一颗牙的范围扩大之后取交集，看集合还是否存在
        if (l2 > r2)
            return 0;
        l = l2, r = r2;
    }
    return 1;
}

void solve()
{

    cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> d[i];
        sum += u[i] + d[i];
    }
    int mx = 1e18;
    for (int i = 1; i <= n; i++)
    {
        mx = min(mx, u[i] + d[i]); // 最小的和，无需修改,一定是上界
    }
    int l = 0, r = mx, m;
    int ans = 0;
    while (l + 1 < r)
    {
        int m = l + r >> 1;
        if (chk(m))
            l = m;
        else
            r = m;
    }
    int h = 0;
    if (chk(r))
        h = r;
    else
        h = l;
    cout << sum - n * h << '\n';
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
