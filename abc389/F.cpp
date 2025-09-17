#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, q;
int L[N], R[N];
// 树状数组这里维护的是差分数组，区间修改，单点查询
namespace BIT
{
    int tr[N];

    void update(int p, int k)
    {
        for (; p < N; p += (p & -p))
        {
            tr[p] += k;
        }
    }

    int query(int p)
    {
        int res = 0;
        for (; p; p -= (p & -p))
        {
            res += tr[p];
        }
        return res;
    }
}
using namespace BIT;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i] >> R[i];
        int l = 1, r = L[i];
        // 二分查找最小的左端点，可以从这里通过这个比赛
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (m + query(m) >= L[i])
                r = m;
            else
                l = m;
        }
        int now_l = 0;
        if (l + query(l) >= L[i])
            now_l = l;
        else
            int now_l = r;

        l = 1, r = R[i];
        // 二分查找最大的左端点，可以从这里通过这个比赛
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (m + query(m) <= R[i])
            {
                l = m;
            }
            else
                r = m;
        }
        int now_r = 0;
        if (r + query(r) <= R[i])
            now_r = r;
        else
            now_r = l;

        update(now_l, 1);
        update(now_r + 1, -1);
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << x + query(x) << '\n';
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
