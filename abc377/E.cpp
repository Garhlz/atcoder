#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[N], vis[N], pos[N];
vector<int> v[N];
void dfs(int x, int cnt) {
    if (vis[x]) return;
    vis[x] = 1;
    v[cnt].push_back(x);
    pos[x] = v[cnt].size() - 1;
    dfs(a[x], cnt);
}
/*
1 5 2 6 4 1
3 3
*/

int qpow(int a, int b, int m) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        b <<= 1;
        a = a * a % m;
    }
    return ret;
}
void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, cnt++);
    }
    vector<int> ans(n + 1);
    for (int i = 0; i < cnt; i++) {
        for (int x : v[i]) {
            int siz = v[i].size();
            int p1 = (pos[x] + qpow(2, k, siz)) % siz;
            ans[x] = v[i][p1];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
/*
3 1 2
2 3 1
3 1 2

2 3 1
3 1 2
2 3 1

2 3 1

4 1 2 3
3 4 1 2
1 2 3 4

4 3 1 2
2 1 4 3
1 2 3 4

3 1 4 2
1 3 4 2 1
4 3 2 1
1 2 3 4

2 3 4 5 1
3 4 5 1 2
5 1 2 3 4
4 5 1 2 3
2 3 4 5 1

2 6 4 1 3 5

1 2 6 5 3 4 1

6 5 1 2 4 3
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
