#include <bits/stdc++.h>

#include <iterator>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
对于每个0, 如果最左侧的1可以跳过去, 则可以?
不一定, 有可能需要
但是全部无脑转移到挨着0的1也可
*/
int c[2003], a[2003];
void solve() {
    int n;
    cin >> n;
    n--;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int num1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) num1++;
    }
    int f1 = 0;
    vector<vector<int>> ans;
    for (int i = n; i >= 1; i--) {
        if (!f1 && !a[i]) continue;
        f1 = 1;
        if (a[i] && i > 1) {
            if (a[i - 1]) {
                continue;
            } else {
                int now = c[i];
                vector<int> tmp;
                i--;
                tmp.push_back(now);
                while (i >= 1 && !a[i]) {
                    tmp.push_back(c[i]);
                    i--;
                }

                ans.emplace_back(tmp);  // 第一位是出发的长度, 后面都是长度
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        int now = 1e18;
        int nn = ans[i].size();
        vector<int> dp(nn, 1e18);
        dp[0] = 0;
        for (int j = 0; j < nn; j++) {
            int len = ans[i][j];
            if (j + len >= nn) {
                now = min(now, dp[j]);
                continue;
            }
            for (int k = j + 1; k <= min(j + len, nn - 1); k++) {
                dp[k] = min(dp[k], dp[j] + 1);
            }
        }
        sum += now;
    }
    cout << num1 + sum << '\n';
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
