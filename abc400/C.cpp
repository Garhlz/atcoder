#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1;; a++) {
        int now = (1ll << a);
        int t = n / now;
        if (t == 0) break;
        int t1 = (int)sqrt(t);
        if (t1 & 1) ans++;
        ans += t1 / 2;
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
