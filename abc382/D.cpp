#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n, m;
int cnt = 0;
int a[13];
vector<int> ans;

void dfs(int pos) {
    if (pos > n) {
        for (int i = 1; i <= n; i++) {
            ans.push_back(a[i]);
        }
        cnt++;
        ans.push_back(-1);
        return;
    }

    if (a[pos - 1] + 10 * (n - pos) > m) return;
    for (int i = a[pos - 1] + 10; i <= m - 10 * (n - pos); i++) {
        a[pos] = i;
        dfs(pos + 1);
    }
}

void solve() {
    cin >> n >> m;
    a[0] = -9;
    dfs(1);
    cout << cnt << '\n';
    for (auto x : ans) {
        if (x == -1)
            cout << '\n';
        else
            cout << x << ' ';
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
