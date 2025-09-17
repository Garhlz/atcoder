#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
vector<int> pos[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pre(n + 1), suf(n + 1),
        sum(m + 1);  // 分别预处理出到当前的相同数字的数量，直接用一维数组表示即可
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> cnt1(m), cnt2(m);
    for (int i = 1; i <= n; i++) {
        pre[i] = ++cnt1[a[i]];  // 换一种方式统计，稍微方便一些
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = ++cnt2[a[i]];
    }

    auto update = [&](int x, int k) {
        x++;  // 原本的数字是从0开始的，所以要加1
        for (int i = x; i <= m; i += i & -i) {
            sum[i] += k;
        }
    };

    auto query = [&](int x) {
        x++;
        int res = 0;
        for (int i = x; i; i -= i & -i) {
            res += sum[i];
        }
        return res;
    };

    int ans = 0;

    for (int i = n; i >= 1; i--) {
        ans += query(a[i] - 1);
        update(a[i], 1);
    }

    for (int i = 0; i < m; i++) {
        cout << ans << '\n';
        for (int p : pos[m - 1 - i]) {
            ans -= (n - p) - (suf[p] - 1);
            ans += p - 1 - (pre[p] - 1);
        }
    }
    cout << '\n';
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
/*
7 7
0 1 2 3 4 5 6
*/