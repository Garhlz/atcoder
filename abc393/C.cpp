#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    set<pii> st;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            ans++;
            continue;
        }
        if (a > b)
            swap(a, b);
        if (st.find({a, b}) != st.end())
        {
            ans++;
        }
        else
        {
            st.insert({a, b});
        }
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
