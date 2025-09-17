#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)

struct SegmentTree {
    struct Node {
        int l, r, mx, add;
        Node(int l_ = 0, int r_ = 0, int mx_ = 0, int add_ = 0) : l(l_), r(r_), mx(mx_), add(add_) {}
    };
    vector<Node> tr;
    vector<int> w;
    int n;

    SegmentTree(int size) : n(size) {
        w.resize(n + 1);
        tr.resize(4 * (n + 1));  // 注意动态分配内存
    }

    void up(int x) { tr[x].mx = max(tr[lc(x)].mx, tr[rc(x)].mx); }

    void down(int x) {
        if (tr[x].add) {
            int &now = tr[x].add;
            tr[lc(x)].mx += now;
            tr[rc(x)].mx += now;
            tr[lc(x)].add += now;
            tr[rc(x)].add += now;
            now = 0;
        }
    }

    void build(int x, int l, int r) {
        tr[x] = Node(l, r, 0, 0);
        if (l == r) {
            tr[x].mx = w[l];
            return;
        }
        int m = (l + r) / 2;
        build(lc(x), l, m);
        build(rc(x), m + 1, r);
        up(x);
    }

    void update(int x, int l, int r, int k) {
        if (l <= tr[x].l && tr[x].r <= r) {
            tr[x].mx += k;
            tr[x].add += k;
            return;
        }
        down(x);  // 都是在进入递归之前把缓存的内容push_down
        int m = (tr[x].l + tr[x].r) / 2;
        if (l <= m) update(lc(x), l, r, k);
        if (r > m) update(rc(x), l, r, k);
        up(x);  // 在从递归中回溯之后，把子节点产生的变化传回给当前结点
    }

    int query(int x, int l, int r) {
        if (l <= tr[x].l && tr[x].r <= r) {
            return tr[x].mx;
        }
        down(x);
        int m = (tr[x].l + tr[x].r) / 2;
        int mx = 0;
        if (l <= m) mx = max(mx, query(lc(x), l, r));
        if (m < r) mx = max(mx, query(rc(x), l, r));
        return mx;
    }

    void init(int n) {
        for (int i = 1; i <= n; i++) w[i] = 0;
        build(1, 1, n);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    SegmentTree st(n);  // vector，动态内存分配在堆上
    st.init(n);

    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
        pre[i] = s.size();
    }
    s.clear();
    for (int i = n; i >= 1; i--) {
        s.insert(a[i]);
        suf[i] = s.size();
    }

    map<int, int> last;
    int ans = 0;
    for (int i = n; i >= 2; i--) {
        if (last.count(a[i])) {
            st.update(1, i, last[a[i]] - 1, 1);  // 区间加,因为用间隔左侧的数字表示间隔所在，就不会重复计算贡献
        }
        last[a[i]] = i;
        int now = pre[i - 1] + suf[i];
        now += st.query(1, i, n);
        ans = max(ans, now);  // 需要同步枚举x，因为贡献不可以超过左侧区间，直接同步枚举x即可
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
