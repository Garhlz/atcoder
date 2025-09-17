#include <bits/stdc++.h>

#include <queue>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int q;
    cin >> q;
    priority_queue<int> pq;
    int now = 0;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            pq.push(-now);
            // 这里是关键, 因为新加入的点不可以享受之前的提高, 所以直接设置为-now
            // 因此now不会更新, 简单而优雅
        } else if (op == 2) {
            cin >> x;
            now += x;
        } else {
            cin >> x;
            int ans = 0;
            while (!pq.empty()) {
                if (pq.top() + now >= x) {
                    ans++;
                    pq.pop();
                } else
                    break;
            }
            cout << ans << '\n';
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