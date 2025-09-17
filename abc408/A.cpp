#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 2);
    // 需要注意起始点
    a[1] = 0;
    for (int i = 2; i <= n + 1; i++) cin >> a[i];
    for (int i = 2; i <= n + 1; i++) {
        if (a[i] - a[i - 1] > s) {
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
