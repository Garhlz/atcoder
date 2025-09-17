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
    vector<int> mod(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> mod[i] >> r[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int now, d;
        cin >> now >> d;  // d之后的第一天x, 满足 x % mod[t] == r[t]
        int tmp = d % mod[now];
        if (tmp <= r[now])
            cout << d + r[now] - tmp << '\n';
        else {
            int tt = (d / mod[now] + 1) * mod[now] + r[now];
            cout << tt << '\n';
        }
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
