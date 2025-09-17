#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << 1 << '\n';
        return;
    }
    vector<int> a(n + 1);
    for (int i = 0; i < k; i++) a[i] = 1;
    int now = k;
    for (int i = k, pre = 0; i <= n; i++, pre++) {
        a[i] = now % MOD;
        now = (now + a[i]) % MOD;
        now = (now - a[pre] + MOD) % MOD;
    }
    cout << a[n] % MOD << '\n';
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
