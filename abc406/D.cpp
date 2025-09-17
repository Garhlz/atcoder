#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> h(n + 1), w(m + 1);
    vector<pii> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i][0] >> a[i][1];
        h[a[i][0]].insert(i);
        w[a[i][1]].insert(i);  // 注意插入的是编号
    }
    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cout << h[x].size() << '\n';
            for (int id : h[x]) {
                w[a[id][1]].erase(id);
            }
            h[x].clear();
        } else if (op == 2) {
            cout << w[x].size() << '\n';
            for (int id : w[x]) {
                h[a[id][0]].erase(id);
            }
            w[x].clear();
        }
    }
    // 于是每个点其实只会被删除一次
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
