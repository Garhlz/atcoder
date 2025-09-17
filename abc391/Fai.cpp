#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;
const int M = 1000005;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> pos(M, 0); // 记录每个值的最近位置
    vector<ll> pre(n + 1);
    vector<ll> nxt(n + 1);
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 计算 pre
    for (int i = 1; i <= n; i++)
    {
        pre[i] = max(pos[a[i]], pos[a[i] + 1]);
        pos[a[i]] = i;
    }

    // 计算 nxt
    fill(pos.begin(), pos.end(), n + 1);
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = pos[a[i] + 1];
        pos[a[i]] = i;
    }

    // 计算答案
    for (int i = 1; i <= n; i++)
    {
        ans += (nxt[i] - i) * (i - pre[i]);
    }

    cout << ans << "\n";
    return 0;
}
