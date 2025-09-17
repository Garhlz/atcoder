#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int dp[4100][4100];
int a[13];
int len;
int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    int st = x | y;
    for (int i = 0; i < len; i++) {  // 枚举桌上牌型
        if ((st >> i) & 1) continue;
        for (int j = 0; j < len; j++) {  // 枚举当前先手牌型
            if (!((x >> j) & 1)) continue;
            if (a[j] > a[i]) {
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
    return dp[x][y] = 2;  // 后续不存在必败态，当前态必败
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    len = n + m + l;
    int x = 0, y = 0;
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        x |= (1 << i);
    }
    for (int j = n; j < n + m; j++) {
        y |= (1 << j);
    }
    int ans = dfs(x, y);
    cout << (ans == 1 ? "Takahashi\n" : "Aoki\n");
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
