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
    vector<int> a(n + 1), last(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0, ans = 0, l = 0;
    // l表示当前成立的连续段的起始点
    for (int i = 2; i <= n;) {
        if (a[i] == a[i - 1]) {
            if (l == 0) l = i;
            if (last[a[i]] >= l) {
                cnt -= last[a[i]] - l;
                l = last[a[i]] + 2;
            } else
                cnt += 2;
            last[a[i]] = i;
            i += 2;
        } else {
            if (cnt) {
                i--;
                l = 0;
                cnt = 0;
            } else {
                i++;
            }
        }
        ans = max(ans, cnt);
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