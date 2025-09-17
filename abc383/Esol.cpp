#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
// 关键其实是想到kruskal的原理和这里完全相同, 当前加的边一定是两个点的这条路径中的权值最大的边, 也一定是最小的
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
    // 中间的const不可以去掉, 表示可以用常量调用?
} e[N];
int a[N], b[N];
int fa[N];
int siza[N], sizb[N];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    for (int i = 1; i <= k; ++i)
        cin >> a[i], siza[a[i]]++;  // 以a[i]数字为集合代表结点的集合中的数字数量, 在集合合并时维护
    for (int i = 1; i <= k; ++i) cin >> b[i], sizb[b[i]]++;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    sort(e + 1, e + m + 1);  // 只会调用 <
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx == fy) continue;
        int w = e[i].w;
        int mn = min(siza[fx], sizb[fy]);
        ans += w * mn, siza[fx] -= mn, sizb[fy] -= mn;

        mn = min(sizb[fx], siza[fy]);
        ans += w * mn, sizb[fx] -= mn, siza[fy] -= mn;
        // 把当前的找到的目标点用来连接两个集合的代表结点, 而且正反都要寻找, 因为不知道在哪边, 也有可能都不在,
        // 或者已经找完
        fa[fx] = fy;
        siza[fy] += siza[fx], sizb[fy] += sizb[fx];  // 集合合并之后就转移了数量, 都用代表结点来表示数量了, 非常合理
        siza[fx] = 0, sizb[fx] = 0;
    }
    cout << ans;
    return 0;
}
