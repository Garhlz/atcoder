#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 803;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int c[N], x[N];
int dp[N][N];
// 表示"解决"这段区间所需的最小代价
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        c[n + i] = c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n * 2; i++) {
        dp[i][i] = x[c[i]] + 1;  // 自己单独染色的代价
    }
    for (int len = 2; len <= 2 * n; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            dp[l][r] = dp[l][r - 1] + dp[r][r];
            for (int k = l; k < r; k++) {
                if (c[k] == c[r]) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + r - k + dp[k + 1][r - 1]);
                    // x对应的代价已经计算过了, 只需计算长度的代价
                }
            }
        }
    }
    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        int j = i + n - 1;
        ans = min(ans, dp[i][j]);
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
