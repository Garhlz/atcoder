#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, k, ans;
int a[N];

void dfs(int pos, int num, int sum) {
    if (num == k) {
        ans = max(ans, sum);
        return;
    }
    for (int i = pos + 1; i <= n; i++) {
        dfs(i, num + 1, sum ^ a[i]);
    }
}

void solve() {
    cin >> n >> k;
    k = n - k;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum ^= a[i];
    if (n - k < k) {
        k = n - k;
        sum = 0;
    }
    dfs(0, 0, sum);
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
