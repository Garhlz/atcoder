#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = m; i >= 0; i--) {
        int now = qpow(n, i);
        s += now;
        if (s > 1e9) {
            cout << "inf\n";
            return;
        }
    }
    cout << s << '\n';
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
