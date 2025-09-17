#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
vector<int> v[N];
int fa[N], cnt[N];
// 带权并查集
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(v[i]));
        fa[i] = i;
        cnt[i] = 1;
    }

    cout << v[1].size() << '\n';
    set<int> link;
    for (int t : v[1]) link.insert(t);

    for (int i = 2; i <= n; i++) {  // 总是从大的连接小的
        if (link.find(i) != link.end()) link.erase(i);
        for (int k : v[i]) {
            if (k > i) {
                link.insert(k);
            } else {
                int fa1 = find(i), fa2 = find(k);
                if (fa1 != fa2) {
                    if (fa1 < fa2) swap(fa1, fa2);  // 总是id较小的结点当父亲
                    fa[fa1] = fa2;
                    cnt[fa2] += cnt[fa1];
                }
            }
        }
        int p = find(1), q = find(i);
        if (p == q && cnt[p] == i) {
            cout << link.size() << '\n';
        } else
            cout << -1 << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
