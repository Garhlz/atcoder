#include <bits/stdc++.h>

#include <cstddef>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[102];
vector<int> v[11];
int c[11];
int ans;
int n, m;
// 10个动物园,100动物
/*
暴力搜索和回溯
简单剪枝
*/
int valid() {
    for (int i = 1; i <= m; i++) {
        if (a[i] < 2) return 0;
    }
    return 1;
}
void dfs(int x, int tot) {
    if (valid()) {
        ans = min(ans, tot);
        return;
    }

    if (x > n) return;

    if (tot > ans) return;

    dfs(x + 1, tot);  // 不去当前动物园, 搜索下一个

    int flag = 1;
    for (int y : v[x]) {  // 如果全部>=2,剪枝
        if (a[y] < 2) {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        for (int y : v[x]) {
            a[y]++;
        }
        dfs(x + 1, tot + c[x]);
        for (int y : v[x]) {
            a[y]--;
        }
    } else
        return;

    flag = 1;
    for (int y : v[x]) {  // 如果全部>=1,剪枝
        if (a[y] < 1) {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        for (int y : v[x]) {
            a[y] += 2;
        }
        dfs(x + 1, tot + c[x] * 2);
        for (int y : v[x]) {
            a[y] -= 2;
        }
    } else
        return;
}
void solve() {
    cin >> n >> m;
    ans = 1e18;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            v[t].emplace_back(i);
        }
    }
    dfs(1, 0);
    cout << ans << '\n';
}

/*
4 3
1000 300 700 200
3 1 3 4
3 1 2 4
2 1 3

*/
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
