#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int now = s[n - 1] - '0';
    for (int i = n - 2; i >= 0; i--) {
        int t = s[i] - '0';
        if (t < now) {
            t += now / 10 * 10;
        }
        if (t < now) t += 10;
        now = t;
    }
    cout << now + n << '\n';
}
// 2025524202552420255242025524

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
