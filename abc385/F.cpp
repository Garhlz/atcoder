#include <bits/stdc++.h>
using namespace std;

#define pii array<long double, 2>

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto &i : a) {
        cin >> i[0] >> i[1];
    }
    long double ans = -1e100;
    for (int i = 0; i <= n - 2; i++) {
        long double k = (a[i + 1][1] - a[i][1]) / (a[i + 1][0] - a[i][0]);
        long double now = a[i + 1][1] - a[i + 1][0] * k;
        ans = max(ans, now);
    }
    if (ans < 0)
        cout << -1 << '\n';
    else
        cout << fixed << setprecision(12) << ans << '\n';
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
