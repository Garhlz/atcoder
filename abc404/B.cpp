#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void rotate(vector<vector<int>> &a) {
    auto t = a;
    int n = a.size();
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            a[i][j] = t[n - 1 - j][i];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n)), t(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.')
                s[i][j] = 0;
            else
                s[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.')
                t[i][j] = 0;
            else
                t[i][j] = 1;
        }
    }
    int ans = 1e18;
    for (int k = 0; k <= 3; k++) {
        int now = k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] != t[i][j]) now++;
            }
        }
        ans = min(ans, now);
        if (k == 3) break;
        rotate(s);
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
