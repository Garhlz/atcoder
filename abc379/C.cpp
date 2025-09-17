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
    vector<int> a(m), x(m);
    vector<pii> v(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
        v[i] = {x[i], a[i]};
    }
    sort(all(v));
    if (sum != n || v[0][0] != 1) {
        cout << -1 << '\n';
        return;
    }
    // 最后每个格子恰好一个石头,直接遍历即可
    int ans = 0;
    for (int i = 1; i < m; i++) {
        int dif = v[i][0] - v[i - 1][0] - 1;
        int now = v[i - 1][1] - 1;
        if (now >= dif) {
            ans += dif * (dif + 1) / 2;
            now -= dif;
            ans += now * (dif + 1);
            v[i][1] += now;
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    int dif = n - v[m - 1][0];
    int now = v[m - 1][1];
    if (now >= dif) {
        ans += dif * (dif + 1) / 2;
    } else {
        cout << -1 << '\n';
        return;
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
/*
5 2
1 4
3 2
*/
