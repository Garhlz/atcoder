#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
单点修改
区间修改
区间查询
权值线段树或者可持续化权值线段树?

*/
void solve() {
    int q;
    cin >> q;
    priority_queue<int> pq;
    int now = 0;
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            pq.push(0);
        } else if (op == 2) {
            int T;
            cin >> T;
            now += T;
        } else {
            int h;
            cin >> h;
            int ans = 0;
            while (!pq.empty()) {
                if (pq.top() + now >= h) {
                    ans++;
                    pq.pop();
                } else
                    break;
            }
            cout << ans << '\n';
            vector<int> tmp;
            while (!pq.empty()) {
                tmp.push_back(pq.top() + now);
                pq.pop();
            }
            for (int x : tmp) {
                pq.push(x);
            }
            now = 0;
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
