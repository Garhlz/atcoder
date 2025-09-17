#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
vector<int> v[N];
vector<int> cnt;
int flag, ans;
int fa[N], tot[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
    int n;
    cin >> n;
    cnt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    vector<int> st;

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 3) st.emplace_back(i);
        fa[i] = i;
    }
    for (int x : st) {
        for (int y : v[x]) {
            int f1 = find(x), f2 = find(y);
            if (f1 == f2)
                continue;
            else {
                if (cnt[y] == 3) {
                    fa[f2] = f1;
                    tot[f1] += tot[f2];  // 存储相邻的2的数量
                    tot[f2] = 0;
                } else if (cnt[y] == 2) {
                    tot[f1]++;
                }
            }
        }
    }
    set<int> fast;
    for (int x : st) {
        fast.insert(find(x));
    }
    for (int x : st) {
        int now = tot[x];
        ans += now * (now - 1) / 2;
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
