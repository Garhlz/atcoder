#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void Showball() {
    int n, m, l;
    cin >> n >> m >> l;
    int len = n + m + l;
    vector<int> a(len);
    for (int i = 0; i < len; i++) cin >> a[i];
    vector<vector<int>> dp(4100, vector<int>(4100));

    function<int(int, int)> dfs = [&](int x, int y) {
        if (dp[x][y]) return dp[x][y];
        int st = x + y;                       // 当前玩家手上的牌型
        for (int i = 0; i < len; i++) {       // 枚举桌上牌型
            if (st >> i & 1) continue;        // 说明这张牌不在桌上
            for (int j = 0; j < len; j++) {   // 枚举当前先手牌型
                if (!(x >> j & 1)) continue;  // 说明这张牌不在先手玩家手中
                if (a[j] > a[i]) {            // 可以摸桌上牌
                    int t = x - (1 << j) + (1 << i);
                    int tt = dfs(y, t);
                    // 后续存在必败态，当前态必胜
                    if (tt == 2) return dp[x][y] = 1;
                } else {  // 不能摸桌上牌
                    int t = x - (1 << j);
                    int tt = dfs(y, t);
                    // 后续存在必败态，当前态必胜
                    if (tt == 2) return dp[x][y] = 1;
                }
            }
        }
        // 后续不存在必败态，当前态必败
        return dp[x][y] = 2;
    };

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) x |= 1 << i;
    for (int i = n; i < n + m; i++) y |= 1 << i;

    int ans = dfs(x, y);
    cout << (ans == 1 ? "Takahashi\n" : "Aoki\n");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;

    while (t--) {
        Showball();
    }

    return 0;
}