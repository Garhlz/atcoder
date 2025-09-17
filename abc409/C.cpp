#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n + 1);
    int s = 0;
    int now = 0;
    a[1] = 0;
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        now += t;
        a[i + 1] = now % l;
    }
    /*
    5 6
    4 3 1 2
    */
    if (l % 3) {
        cout << 0 << '\n';
        return;
    }

    sort(a.begin() + 1, a.begin() + 1 + n);  // 直接排序
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }
    auto pos = unique(a.begin() + 1, a.begin() + 1 + n);
    a.erase(pos, a.end());
    int cnt = a.size() - 1;  // 有第一个空的数字

    vector<int> a1(cnt * 2 + 1), pre(2 * cnt + 1), po(2 * cnt + 1, -1), vis(2 * cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        a1[i] = a[i];
        a1[i + cnt] = a[i];
    }
    for (int i = 1; i <= 2 * cnt; i++) {
        pre[i] = pre[i - 1] + a1[i];
    }

    int x = l / 3;
    int fast = 2;

    for (int i = 1; i <= cnt; i++) {
        while (min(l - a[i] + a[fast], a[fast] - a[i]) < x && fast <= 2 * cnt) fast++;
        if (min(l - a[i] + a[fast], a[fast] - a[i]) == x) {
            po[i] = fast;
        } else
            fast--;
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        if (vis[i] || vis[i + cnt]) continue;
        if (po[i] != -1 && po[po[i]] != -1) {
            ans += mp[a1[i]] * mp[a1[po[i]]] * mp[a1[po[po[i]]]];
            vis[i] = vis[po[i]] = vis[po[po[i]]] = 1;
        }
    }
    cout << ans << '\n';
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
