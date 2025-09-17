#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve() {
    int n, m;
    cin >> n >> m;
    set<pii> st;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        for (int j = 0; j < 8; j++) {
            int xx = x + dx[j], yy = y + dy[j];
            if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
            st.insert({xx, yy});
        }
    }
    cout << n * n - st.size() << '\n';
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
