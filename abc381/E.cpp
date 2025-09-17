#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s;
    vector<int> pre(n + 1), suf(n + 1);
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '1') pre[i]++;
        suf[i] = suf[i - 1];
        if (s[i] == '2') suf[i]++;
        if (s[i] == '/') {
            pos.push_back(i);
        }
    }

    while (q--) {
        int L, R;
        cin >> L >> R;
        int idx1 = lower_bound(all(pos), L) - pos.begin();
        int idx2 = upper_bound(all(pos), R) - pos.begin() - 1;
        int ans = 0;
        if (idx2 < idx1) {
            cout << 0 << '\n';
            continue;
        }
        int cnt1 = pre[R] - pre[L - 1];
        int cnt2 = suf[R] - suf[L - 1];
        if (min(cnt1, cnt2) == 0) {  // 剪枝
            cout << 1 << '\n';
            continue;
        }

        for (int i = idx1; i <= idx2; i++) {
            int now = pos[i];  // 表示'/'
            int t1 = pre[now - 1] - pre[L - 1];
            int t2 = suf[R] - suf[now + 1 - 1];
            int cnt = min(t1, t2);
            ans = max(ans, cnt);
        }
        cout << ans * 2 + 1 << '\n';
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
