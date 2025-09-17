#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 8e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> l(m), r(m), s(m);
    for (ll i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> s[i];
    }

    // 建图：邻接表
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 1; i <= n; i++) {
        g[i - 1].push_back({i, 1});  // B_j - B_{j-1} >= 1
    }
    for (ll i = 0; i < m; i++) {
        g[l[i] - 1].push_back({r[i], s[i]});   // B_{R_i} - B_{L_i-1} >= S_i
        g[r[i]].push_back({l[i] - 1, -s[i]});  // B_{L_i-1} - B_{R_i} >= -S_i
    }

    // SPFA
    vector<ll> d(n + 1, INF);
    vector<ll> cnt(n + 1, 0);  // 入队次数
    vector<bool> inq(n + 1, false);
    queue<ll> q;
    d[0] = 0;  // 源点 B_0
    q.push(0);
    inq[0] = true;
    cnt[0] = 1;
    bool neg_cycle = false;

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        inq[u] = false;
        for (auto [v, w] : g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n + 1) {  // 负环
                        neg_cycle = true;
                        break;
                    }
                }
            }
        }
        if (neg_cycle) break;
    }

    if (neg_cycle) {
        cout << "-1\n";
    } else {
        if (d[n] >= INF)
            cout << "-1\n";  // B_N 不可达
        else
            cout << d[n] << "\n";  // 答案 B_N
    }

    return 0;
}