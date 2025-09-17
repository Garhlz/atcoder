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
    vector<int> dif(n + 2, 0);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        dif[l]++;
        dif[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i - 1];
    }
    int mn = INF;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, dif[i]);
    }
    cout << mn << '\n';
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
