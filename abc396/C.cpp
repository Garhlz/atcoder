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
    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    int ans = 0;
    int i = 0;
    for (; i < min(n, m); i++) {
        if (a[i] + b[i] < 0 || b[i] < 0) break;
        ans += a[i] + b[i];
    }
    for (; i < n; i++) {
        if (a[i] > 0)
            ans += a[i];
        else
            break;
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
