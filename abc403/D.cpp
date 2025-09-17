#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        mp[t]++;
    }
    if (k == 0) {
        int ans = 0;
        for (auto &h : mp) {
            if (h.second > 1) {
                ans += h.second - 1;
            }
        }
        cout << ans << '\n';
        return;
    }
    int ans = 0;
    for (auto &h : mp) {
        if (h.first == mp.begin()->first) {
            continue;
        }
        if (mp[h.first - k]) {
            int now = min(h.second, mp[h.first - k]);
            ans += now;
            h.second -= now;
            mp[h.first - k] -= now;
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
