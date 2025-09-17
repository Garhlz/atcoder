#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int a, b;
    cin >> a >> b;
    double t = (double)a / b;
    int t1 = a / b;
    double t2 = t - t1;
    if (t2 < 0.5) {
        cout << t1 << endl;
    } else {
        cout << t1 + 1 << endl;
    }
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
