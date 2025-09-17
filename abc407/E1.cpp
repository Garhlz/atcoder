#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a[1000005], ans, n;
priority_queue<int> q;
signed main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n * 2; i++) cin >> a[i], ans += a[i];
        for (int i = 1; i <= n * 2; i++) {
            q.push(a[i]);
            if (q.size() > i / 2) {
                // cout << q.top() << ' ';
                q.pop();
            }
        }
        while (!q.empty()) ans -= q.top(), q.pop();
        // 最后的q表示右括号, 推出的是左括号
        cout << ans << "\n";
    }
    return 0;
} /*
 1 3
 1 2 3 4 5 6
 */