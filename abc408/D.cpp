#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> a;
    int cnt = 1, type = 0;
    for (int i = 0; i < n; i++) {
        type = s[i] - '0';
        while (i + 1 < n && s[i + 1] == s[i]) i++, cnt++;
        a.push_back({cnt, type});
        cnt = 1;
    }
    vector<vector<int>> dp(2, vector<int>(2));  // 第一维当前有几个连续1片段, 第二维是最后一个片段是否为1的连续段
    // dp[0][1]不可能存在
    // 存储消耗
    if (a[0][1] == 1) {
        dp[1][1] = 0;  // 全删除
        dp[1][0] = INF;
        dp[0][0] = a[0][0];
    } else {
        dp[1][1] = a[0][0];
        dp[1][0] = INF;
        dp[0][0] = 0;
    }
    int tmp = 0;
    for (auto [x, type] : a) {
        tmp++;
        if (tmp == 1) continue;
        if (type == 1) {
            int dp11 = dp[1][1], dp10 = dp[1][0], dp00 = dp[0][0];
            dp[1][1] = min(dp11, dp00);
            dp[1][0] = min(dp11, dp10) + x;
            dp[0][0] = dp00 + x;  // 直接删除
        } else {
            int dp11 = dp[1][1], dp10 = dp[1][0], dp00 = dp[0][0];
            dp[1][1] = min(dp11 + x, dp00 + x);
            dp[1][0] = min(dp11, dp10);
            dp[0][0] = dp00;  // 直接不变
        }
    }
    cout << min(min(dp[1][1], dp[1][0]), dp[0][0]) << '\n';
}
/*
5
2
01
10
1000010011
12
111100010011
3
111
8
00010101

*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
