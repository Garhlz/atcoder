#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    map<int, int> last;

    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 2; i <= n; i += 2) {
        if (a[i] == a[i - 1]) {
            int now = a[i];
            if (last[now]) {
                if (i - 2 - last[now] + 2 <= dp[i - 2]) {  // 在其中
                    dp[i] = i - last[now];
                    last[now] = i;
                } else {
                    dp[i] = dp[i - 2] + 2;
                    last[now] = i;
                }
            } else {
                dp[i] = dp[i - 2] + 2;
                last[now] = i;
            }
        } else {
            last.clear();
            i--;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
// 1 1 2 2 3 3 1 1
//  last     i-2

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
8
2 3 1 1 2 2 1 1

*/