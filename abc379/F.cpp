#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<vector<pii>> query(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        query[l].emplace_back(r, i);
    }
    vector<int> st(n + 1), ans(q + 1);
    int tot = 0;
    for (int i = n; i >= 1; i--) {
        for (auto [j, id] : query[i]) {
            int l = 1, r = tot;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (st[m] > j)
                    l = m;
                else
                    r = m - 1;
            }
            if (st[l] <= j)
                ans[id] = 0;
            else
                ans[id] = l;
        }
        // 入栈, 需要所有比它小的都要出栈
        while (tot && a[st[tot]] < a[i]) tot--;
        st[++tot] = i;
    }
    for (int i = 1; i <= q; i++) {
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