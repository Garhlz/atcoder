#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
constexpr int INF = 0x3f3f3f3f;
int n;
vector<int> a;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    a.resize(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = INF;

    vector<int> lpos(n + 1), rpos(n + 1);
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i <= n; i++) {
        while (a[i] > a[stk.top()]) stk.pop();
        lpos[i] = stk.top() + 1;
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    stk.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (a[i] >= a[stk.top()]) stk.pop();
        rpos[i] = stk.top() - 1;
        stk.push(i);
    }

    vector<i64> ans(n + 3);
    for (int i = 1; i <= n; i++) {
        int len = rpos[i] - lpos[i] + 1;
        auto [x1, x2] = minmax({i - lpos[i] + 1, rpos[i] - i + 1});
        ans[1] += a[i], ans[x1 + 1] -= a[i], ans[x2 + 1] -= a[i], ans[len + 2] += a[i];
    }

    partial_sum(ans.begin(), ans.end(), ans.begin());
    partial_sum(ans.begin(), ans.end(), ans.begin());

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}