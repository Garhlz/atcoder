#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
int n, Q, a[N];
int st[N], tot, ans[N];
vector<pii> query[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> Q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, l, r; i <= Q; ++i) cin >> l >> r, query[l].emplace_back(r, i);
    for (int i = n; i; --i) {
        for (auto [j, id] : query[i]) {
            int l = 1, r = tot;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (st[mid] > j)
                    l = mid;
                else
                    r = mid - 1;
            }
            if (st[l] <= j)
                ans[id] = 0;  // 单调栈中不存在位置大于 j 的点
            else
                ans[id] = l;
        }
        while (tot && a[st[tot]] < a[i]) --tot;
        st[++tot] = i;
    }
    for (int i = 1; i <= Q; ++i) cout << ans[i] << '\n';
    return 0;
}