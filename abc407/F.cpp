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
    vector<int> a(n + 1), dif(n + 10), pred(n + 1, 0), next(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    // 这里注意不重不漏, 一边可以相等, 一遍不可以
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        if (st.empty())
            pred[i] = 0;
        else
            pred[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty())
            next[i] = n + 1;
        else
            next[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int t1 = i - pred[i], t2 = next[i] - i;
        dif[1] += a[i];
        dif[t1 + 1] -= a[i];
        dif[1] += a[i];
        dif[t2 + 1] -= a[i];
        dif[1] -= a[i];
        dif[2] += a[i];

        int len0 = i - pred[i], len1 = next[i] - i;
        if (len0 > 1 && len1 > 1) {  // 这里可以用二维差分数组优化掉. 观察到增量是先上升, 后不变, 再下降
            for (int k = 3; k <= len1 + 1; k++) {
                dif[k] += a[i];
                dif[k + len0 - 1] -= a[i];
            }
        }
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + dif[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
/*
6
1 2 3 4 1 2

8
2 0 2 5 0 5 2 4

8
0 0 0 5 0 0 0 4

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
