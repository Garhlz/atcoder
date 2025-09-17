#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int f[N][45];
int& dp(int i, int j) {  // 返回一个引用,直接赋值传值即可
    return f[i][i - j + 22];
}
/*
类似经典的dp编辑距离问题,但是需要根据操作次数限制优化空间和时间
*/
void solve() {
    int k;
    string s, t;
    cin >> k >> s >> t;
    int n = s.size(), m = t.size();
    if (abs(n - m) > k) {
        cout << "No\n";
        return;
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= k; i++) {
        dp(0, i) = i;
        dp(i, 0) = i;
    }  // 纯插入和删除操作
    for (int i = 1; i <= n; i++) {
        for (int j = max(1, i - k); j <= min(i + k, m); j++) {
            dp(i, j) = min(min(dp(i - 1, j) + 1, dp(i, j - 1) + 1), dp(i - 1, j - 1) + (s[i - 1] != t[j - 1]));
        }
    }
    if (dp(n, m) <= k) {
        cout << "Yes\n";
    } else
        cout << "No\n";
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
