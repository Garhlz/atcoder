#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
int a[N], dp[N][N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] == a[i - j]) dp[i][j] = dp[i - j][j] + 1;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
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