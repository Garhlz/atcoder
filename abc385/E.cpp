#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

vector<int> v[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(all(v[i]), [](int a, int b) { return v[a].size() < v[b].size(); });
        for (int j = 0; j < v[i].size(); j++) {
            int neighbor = v[i].size() - j;    // 当前剩余邻居数量
            int leaf = v[v[i][j]].size() - 1;  // 当前需要保留的邻居中, 最小的叶子数量
            // 因为排序了, 最小的序号也就有最小的叶子数量
            ans = max(ans, leaf * neighbor + neighbor + 1);
        }
    }
    cout << n - ans << '\n';
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
