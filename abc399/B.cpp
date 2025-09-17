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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    int now = 1;
    sort(all(a), [&](pii a, pii b) { return a[0] > b[0]; });
    vector<int> ans(n);
    ans[a[0][1]] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i - 1][0]) {
            ans[a[i][1]] = now;
        } else {
            ans[a[i][1]] = i + 1;
            now = i + 1;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    // cout << '\n';
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
