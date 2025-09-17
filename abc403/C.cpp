#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> a(n + 1);
    vector<int> vis(n + 1);
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (vis[x]) continue;
            a[x].insert(y);
        } else if (op == 2) {
            cin >> x;
            vis[x] = 1;
        } else {
            cin >> x >> y;
            if (vis[x]) {
                cout << "Yes\n";
            } else {
                auto it = a[x].find(y);
                if (it != a[x].end()) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
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
