#include <bits/stdc++.h>

#include <iomanip>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= x || abs(i - j) >= y) {
                ans++;
            }
        }
    }
    double t = ans / 36.0;  // 总共有6*6=36种情况
    cout << fixed << setprecision(11) << t << '\n';
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
