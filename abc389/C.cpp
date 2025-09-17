#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int q;
    cin >> q;
    vector<int> a(q + 1);
    int st = 0, ed = 0, now = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l;
            cin >> l;
            if (st == ed) {
                now = l;
                a[++ed] = 0;
            } else {
                a[++ed] = now;
                now += l;
            }
        } else if (op == 2) {
            st++;
        } else {
            int k;
            cin >> k;
            cout << a[st + k] - a[st + 1] << '\n';
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
