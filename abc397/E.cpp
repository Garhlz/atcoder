#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
u可以连接两条子路径（长度和为k - 1）形成一条完整路径，但之后u被用掉，不能再连接其他路径。
如果u不连接两条路径，则子树内只能有一条未完成路径通过u向上传递。

*/
int n, k;
vector<int> a[N];
int c[N];

void dfs(int x, int f) {
    map<int, int> mp;  // 未完成的路径长度及其数量
    mp[0] = INT_MAX;
    int flag = 0;
    for (auto y : a[x]) {
        if (y == f) continue;
        dfs(y, x);
        int now = c[y];
        if (now == k || now == 0) continue;  // 子树已经完成
        if (mp[k - now - 1] > 0) {           // 恰好存在符合条件的路径
            if (flag) {
                cout << "No\n";  // 已经使用过当前结点x
                exit(0);
            }
            mp[k - now - 1]--;  // 经过x的一条链
            flag = 1;
        } else
            mp[now]++;
    }
    int remain = 0;

    for (auto [len, cnt] : mp) {
        if (len > 0 && cnt > 0) {
            if (remain) {
                cout << "No\n";
                exit(0);
            }  // 已经存在一个未完成路径
            if (flag) {
                cout << "No\n";
                exit(0);
            }  // 该顶点x已经使用
            if (cnt > 1) {  // 应该也不可以有多条路径
                cout << "No\n";
                exit(0);
            }
            remain = len;  // 唯一可以存在的未完成路径
        }
    }
    c[x] = remain;
    if (!flag) c[x]++;  // 这个顶点还未使用,剩下的长度要加一（其实如果会留下长度，一定会加)
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n * k - 1; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (k == 1) {
        cout << "Yes\n";
        return;
    }
    dfs(1, 0);
    if (c[1] == k || c[1] == 0)  // 之前的顶点都连接到了唯一的链条上，剩下一条。如果之前有问题已经判掉
        cout << "Yes\n";
    else
        cout << "No\n";
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
