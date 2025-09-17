#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }
    vector<double> g(n + 1, 0.0);
    g[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = n; j >= 1; j--) {
            g[j] = g[j] * (1.0 - p[i]) + g[j - 1] * p[i];
        }
        g[0] *= (1.0 - p[i]);
    }

    vector<double> f(x + 1, 0.0);

    for (int i = 1; i <= x; i++) {
        f[i] = 1.0;
        for (int j = 1; j <= n; j++) {
            f[i] += f[max(0, i - j)] * g[j];
        }
        f[i] /= (1.0 - g[0]);
    }
    cout << fixed << setprecision(10) << f[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
