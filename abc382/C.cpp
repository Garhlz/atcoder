#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct pii {
    int a, b;
    bool operator<(const pii& other) const { return a < other.a; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<pii> b(m);
    vector<int> ans(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        b[i] = {t, i};
    }
    sort(all(b));

    int last = m;
    for (int i = 0; i < n; i++) {
        pii tmp = {a[i], 0};
        auto it = lower_bound(all(b), tmp);  // 大于等于这个数值的都会被i+1吃掉
        if (it == b.end()) continue;
        int pos = it - b.begin();
        if (pos >= last) continue;
        for (int j = pos; j < last; j++) {
            int now = b[j].b;
            ans[now] = i + 1;
        }
        last = pos;
    }
    for (int i = 0; i < m; i++) {
        if (!ans[i])
            cout << -1 << '\n';
        else
            cout << ans[i] << '\n';
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
