#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct edge {
    int u, v, w, cu = 1;
} e[N];
int fa[N];
int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int ans = 0;
    for (int t = 30; ~t; t--) {
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= m; i++) {
            int fu = find(e[i].u), fv = find(e[i].v);
            if (fu == fv || !e[i].cu || (e[i].w >> t & 1)) continue;
            // 不可以使用, 侵犯了之前的不可使用位条件的边, 或者当前条件不满足的边
            fa[fu] = fv;
            // 使用这条边可用的边相连
        }
        if (find(n) == find(1)) {
            for (int i = 1; i <= m; i++)
                if (e[i].w >> t & 1) e[i].cu = 0;
            // 如果可以通过使用满足这一位全是0的边到达n
            // 则将所有这一位=1的设置为后续不可用状态
        } else
            ans += 1 << t;
    }
    cout << ans;
}