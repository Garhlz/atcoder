#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define ls (p << 1)
#define rs (p << 1 | 1)
#define pii array<int, 2>
const int N = 5e5 + 10;
const int INF = 1e9;
const int MOD = 998244353;

struct Seg {
    int mx[N << 2];
    void push_up(int p) { mx[p] = max(mx[ls], mx[rs]); }

    void build(int p, int l, int r) {
        mx[p] = -INF;
        if (l == r) return;
        int m = (l + r) / 2;
        build(ls, l, m);
        build(rs, m + 1, r);
    }

    // 只需要单点修改, 所以其实不需要懒标记
    // 而且目标也只是一个结点
    void update(int p, int l, int r, int x, int v) {
        if (l == r)
            mx[p] = max(mx[p], v);
        else {
            int m = (l + r) / 2;
            if (x <= m) update(ls, l, m, x, v);
            if (x > m) update(rs, m + 1, r, x, v);
            push_up(p);
        }
    }

    int query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mx[p];
        }
        int m = (l + r) / 2;
        int res = -INF;
        if (L <= m) res = max(res, query(ls, l, m, L, R));
        if (R > m) res = max(res, query(rs, m + 1, r, L, R));
        return res;
    }
} tr;

struct node {
    int h, id, dp;
} a[N];

void solve() {
    int n, d, r;
    cin >> n >> d >> r;  // r是区间范围, d是减去的数字范围
    for (int i = 1; i <= n; i++) {
        cin >> a[i].h;
        a[i].id = i, a[i].dp = 1;  // 初始只有这个点自己
    }
    tr.build(1, 1, n);
    sort(a + 1, a + 1 + n, [&](node x, node y) { return x.h < y.h; });
    // 因为是排列...按照从小到大排序, 高度较小的先处理, 因此i+d就可以从当前已经处理过的所有点开始转移
    for (int i = 1; i <= n; i++) {
        tr.update(1, 1, n, a[i].id, a[i].dp);
        int j = i + d;
        if (j <= n) {
            int now = tr.query(1, 1, n, max(1ll, a[j].id - r),
                               min(n, a[j].id + r));  // 可以访问的区间的最大dp值, 通过线段树进行优化
            now = max(now + 1, 1ll);
            a[j].dp = max(a[j].dp, now);
        }
    }
    cout << tr.query(1, 1, n, 1, n) - 1 << '\n';
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
