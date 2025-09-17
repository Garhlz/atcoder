#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10;
int n, p[N];
ll m;

inline bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ll k = (x + p[i]) / (2ll * p[i]);
        if (k > 1e9 || p[i] > 2e18 / (k * k))
            return false; // 提前防溢出
        ll cost = k * k * p[i];
        if (cost > m - cnt)
            return false;
        cnt += cost;
    }
    return true;
}

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    ll l = 0, r = m;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll k = (l + p[i]) / (2 * p[i]);
        m -= k * k * p[i];
        ans += k;
    }
    ans += m / (l + 1);
    printf("%lld\n", ans);
    return 0;
}