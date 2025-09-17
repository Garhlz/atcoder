#include <bits/stdc++.h>

#include <cstdint>
#include <queue>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define tup array<int, 3>
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int dis(pii a, pii b) { return abs(a[0] - b[0]) + abs(a[1] - b[1]); }
int fa[3003];
vector<pii> v(3003);
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    priority_queue<tup, vector<tup>, greater<tup> > pq;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pq.push({dis(v[i], v[j]), i, j});
        }
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    while (q--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            n++;
            v[n] = {a, b};
            for (int i = 1; i < n; i++) {  // 加入优先队列
                pq.push({dis(v[i], v[n]), i, n});
            }
            fa[n] = n;
        } else if (op == 2) {
            int flag = 0, mn = INT32_MAX;
            while (!pq.empty()) {
                auto [d, a, b] = pq.top();
                pq.pop();
                int f1 = find(a), f2 = find(b);
                if (f1 == f2) continue;
                // 否则就是找到了
                flag = 1;
                fa[f1] = f2;
                mn = d;
                break;
            }
            while (!pq.empty() && flag) {
                auto [d, a, b] = pq.top();
                if (d == mn) {
                    pq.pop();
                    int f1 = find(a), f2 = find(b);
                    if (f1 != f2) fa[f1] = f2;
                } else
                    break;
            }
            if (flag)
                cout << mn << '\n';
            else
                cout << -1 << '\n';
        } else if (op == 3) {
            cin >> a >> b;
            int f1 = find(a), f2 = find(b);
            if (f1 == f2)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
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
