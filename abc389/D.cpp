#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int r;
    cin >> r;
    int ans = 0;
    for (int i = -r; i < r; i++) {
        if (i == 0) continue;
        double x = i + 0.5;
        double y = r * r - x * x;
        y = sqrtl(y) + 0.5;
        ans += 2 * (floor(y))-1;
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
