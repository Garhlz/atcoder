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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a), greater<int>());
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (a[i] >= cnt) ans = max(ans, cnt);   // 取cnt这个数字, 因为此前取到的a[i] >= cnt
        if (cnt >= a[i]) ans = max(ans, a[i]);  // 取当前的a[i]
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
