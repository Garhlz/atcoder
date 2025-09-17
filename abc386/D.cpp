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
    vector<int> b(n + 1, 0), w(n + 1, n + 1);
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'B') {
            a[x][y] = 1;
        } else
            a[x][y] = 2;
    }
    for (int i = 1; i <= n; i++) {
        int mx = 0, mn = n;  // 最右的黑,最左的白
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) mx = max(mx, j);
            if (a[i][j] == 2) mn = min(mn, j);
        }
        if (mn < mx) {
            cout << "No\n";
            return;
        }
        b[i] = mx;
        w[i] = mn;
    }

    for (int j = 1; j <= n; j++) {
        int mx = 0, mn = n;  // 最下的黑,最上的白
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) mx = max(mx, i);
            if (a[i][j] == 2) mn = min(mn, i);
        }
        if (mn < mx) {
            cout << "No\n";
            return;
        }
    }

    for (int i = 2; i <= n; i++) {
        w[i] = min(w[i], w[i - 1]);  // 前缀最小值
    }

    for (int i = n; i >= 1; i--) {
        if (w[i] < b[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
