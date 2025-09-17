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
    string ss, tt;
    cin >> n >> ss >> tt;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) s[i] = ss[i] - 'a' + 1;
    for (int i = 0; i < n; i++) t[i] = tt[i] - 'a' + 1;
    // 改成数字存储,1base
    vector<int> in[27], v(27), vis(27), mp(27);

    for (int i = 0; i < n; i++) {
        if (!mp[s[i]]) {
            mp[s[i]] = t[i];
            // 这里不要先直接加入in,因为可能存在自环
            v[t[i]]++;
        } else {
            if (t[i] != mp[s[i]]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    int tmp = 0;
    for (int i = 1; i <= 26; i++) {
        if (v[i]) tmp++;
    }
    if (s != t && tmp == 26) {  // 这个分析是显然的,手推一下即可
        cout << -1 << '\n';
        return;
    }
    int ans = 0;

    for (int i = 1; i <= 26; i++) {
        if (mp[i] == i) {
            mp[i] = 0;
        } else if (mp[i]) {
            in[mp[i]].push_back(i);
            ans++;  // 多一个映射关系
            // 注意只要存在多对一关系的环,就不需要额外的空间
            // 对于没有这种关系的环,必须要使用额外的空间,就要多一个操作数
        }
    }
    int rt = 0;
    function<void(int)> dfs = [&](int x) {
        if (x == 0) return;
        if (vis[x]) {
            if (x == rt) ans++;
            return;
        }
        vis[x] = 1;
        dfs(mp[x]);  // 这里是脑子糊涂了,只需要mp映射就够了,不用建立反向边
    };

    for (int i = 1; i <= 26; i++) {
        if (in[i].size() > 1) {
            if (!vis[i]) dfs(i);
        }
    }

    for (int i = 1; i <= 26; i++) {
        if (!vis[i]) {
            rt = i;
            dfs(i);
        }
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