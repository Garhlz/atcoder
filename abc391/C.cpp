#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int fa[N], cnt[N];
/*
问题在于不是并查集，搞错了，集合不用集合的代表节点表示
*/
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        fa[i] = i, cnt[i] = 1;
    int ans = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, h;
            cin >> p >> h;
            int f = fa[p];
            if (f == h)
                continue;
            cnt[f]--;
            if (cnt[f] == 1)
                ans--;
            fa[p] = h;
            cnt[h]++;
            if (cnt[h] == 2)
                ans++;
        }
        else
        {
            cout << ans << '\n';
        }
    }
}
/*
1 2 3 4 5
1 2 3 4 5
1 2 3,4 0 5
1 2 3 0 5,4
1,3 2 0 0 5,4
1,3 0 2 0 5,4
1,3 0 0 0 5,4,2
3 0 1 0 5,4,2

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
