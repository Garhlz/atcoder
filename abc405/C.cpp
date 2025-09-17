#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int,2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n;cin>>n;
    vector<int> a(n+1),pre(n+1);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans += a[i] * (pre[n] - pre[i]);
    }
    cout<<ans<<'\n';
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
