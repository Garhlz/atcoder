#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct edge {
    int to, nxt, w;
} e[N << 1];

int cnt, head[N];
void add(int a, int b, int c) {
    e[++cnt] = {b, head[a], c};
    head[a] = cnt;
}
priority_queue<pii, vector<pii>, greater<pii> > pq;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    vector<int> vis(n + 1);
    vector<int> dis(n + 1, INF);
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to;
            if (d | e[i].w < dis[y]) {
                dis[y] = d | e[i].w;
                if (!vis[y]) pq.push({dis[y], y});
            }
        }
    }
    cout << dis[n] << '\n';
}
/*
4 5
1 2 1
1 3 4
2 3 2
2 4 4
3 4 3

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
