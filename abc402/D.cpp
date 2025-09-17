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
    map<int, int> mp;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        int t = (a + b) % n;
        mp[t]++;
    }
    int tmp = 0;
    for (auto h : mp) {
        int num = h.second;
        tmp += num * (num - 1) / 2;
    }
    int ans = m * (m - 1) / 2 - tmp;
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
