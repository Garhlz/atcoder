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
        auto func = [&](int m) {
            int now = pos[m];  // 表示'/'
            int t1 = pre[now - 1] - pre[L - 1];
            int t2 = suf[R] - suf[now + 1 - 1];
            return min(t1, t2);
        };
        int l = idx1, r = idx2;
        int ans = 0;
        if (r - l <= 2) {  // 注意这里要判断
            int tt1 = func(l), tt2 = func(r);
            ans = max(tt1, tt2);
        }
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int now = pos[m];                    // 表示'/'
            int t1 = pre[now - 1] - pre[L - 1];  // 1的数量
            int t2 = suf[R] - suf[now + 1 - 1];
            if (t1 > t2)
                r = m;
            else
                l = m;
            int tt1 = func(l), tt2 = func(r);
            ans = max(tt1, tt2);
        }

        cout << ans * 2 + 1 << '\n';
        // 1 1 1 1 / 2 2 / 2 2
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
/*
12 5
111/212/1122
1 7
9 12
3 6
4 10
1 12
*/