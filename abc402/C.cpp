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
    vector<vector<int>> a(m + 1);
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        while (t--) {
            int x;
            cin >> x;
            a[i].emplace_back(x);
        }
    }
    vector<int> proj(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        proj[t] = i;
    }
    vector<int> due(n + 1);
    for (int i = 1; i <= m; i++) {
        int mx = 1;
        for (auto x : a[i]) {
            int now = proj[x];
            mx = max(mx, now);
        }
        due[mx]++;
    }
    for (int i = 1; i <= n; i++) {
        due[i] += due[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << due[i] << "\n";
    }
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
