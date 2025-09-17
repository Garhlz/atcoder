#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> mn(m + 1, m + 1), suf(m + 2, m + 1);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mn[a] = min(mn[a], b);  // 对于每个l来说最近的r
    }

    for (int i = m; i >= 1; i--) {
        suf[i] = min(suf[i + 1], mn[i]);  // 后缀的最近数值的最小值
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += suf[i] - 1 - i + 1;
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
