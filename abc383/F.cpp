#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> pri[502];  // 颜色, 序号, 存储价格
vector<int> use[502];  // 效用
int dp[502][50004];
void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    for (int i = 1; i <= n; i++) {
        int p, u, c;
        cin >> p >> u >> c;
        pri[c].push_back(p);
        use[c].push_back(u);
    }
    for (int i = 1; i <= n; i++) {      // 颜色,也就是分组
        for (int j = 0; j <= x; j++) {  // x表示最大价格
            dp[i][j] = dp[i - 1][j];    // 暂时不取
        }
        for (int j = 0; j < pri[i].size(); j++) {
            int pri_cur = pri[i][j], use_cur = use[i][j];
            for (int w = x; w >= pri_cur; w--) {
                dp[i][w] = max(dp[i][w], max(dp[i - 1][w - pri_cur] + use_cur + k, dp[i][w - pri_cur] + use_cur));
            }
        }
    }  // 看似三层循环, 实际上外面两层只是所有的物品, 加起来就是n, 很小
    // 最内层固定5e4, 乘起来2e7
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            ans = max(ans, dp[i][j]);
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
