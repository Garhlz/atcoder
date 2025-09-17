#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct edge {
    int to, nxt;
} e[N << 1];
int head[N], cnt, vis[N];
void add(int a, int b) {
    e[++cnt] = {b, head[a]};
    head[a] = cnt;
}
int ans;
int n;
void dfs(int x, int f, int dep) {
    if (x == 1 && vis[1]) {
        if (dep == n) {
            ans = 1;
        }
        return;
    }
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        if (y != 1 && vis[y]) continue;

        dfs(y, x, dep + 1);
    }
}
void solve() {
    int m;
    cin >> n >> m;
    if (m == 0) {
        cout << "No\n";
        return;
    }
    if (m != n) {
        while (m--) {
            int a, b;
            cin >> a >> b;
        }
        cout << "No\n";
        return;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1, 0, 0);
    cout << (ans == 1 ? "Yes\n" : "No\n");
}

/*
4 4
2 4
3 1
4 1
2 3

4 4
1 2  2 3  1 3  3 4
*/
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
