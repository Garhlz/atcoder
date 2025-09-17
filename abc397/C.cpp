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
    vector<int> a(n), pre(n), suf(n);
    for (auto &i : a) cin >> i;
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
        pre[i] = st.size();
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        st.insert(a[i]);
        suf[i] = st.size();
    }
    int ans = 0;
    for (int i = 0; i <= n - 2; i++) {
        ans = max(ans, pre[i] + suf[i + 1]);
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
