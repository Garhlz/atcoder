#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct Trie {
    vector<int> ch;
    int zt, ans, fa;
    Trie() : ch(26, 0), zt(0), ans(0), fa(0) {}
};
// zt表示是否为一个x字符串的终结点
// ans表示以当前节点为根的有效y字符串的数量

vector<Trie> t(1);

void insert(int op, const string& s) {
    int now = 0;
    for (char c : s) {               // 移动指针
        if (t[now].zt == 1) return;  // 已经有x经过了
        int id = c - 'a';
        if (!t[now].ch[id]) {
            t.emplace_back();  // 动态扩容
            t[now].ch[id] = t.size() - 1;
            t.back().fa = now;
        }
        now = t[now].ch[id];
    }
    if (t[now].zt == 1) return;

    if (op == 1) {
        t[now].zt = 1;  // x标记终结点
        if (t[now].ans > 0) {
            int del = t[now].ans;
            t[now].ans = 0;
            while (now) {  // 删除这个子树的所有结点数量
                now = t[now].fa;
                t[now].ans -= del;
            }
        }
    } else {
        t[now].ans++;
        while (now) {
            now = t[now].fa;
            t[now].ans++;
        }
    }
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int op;
        string s;
        cin >> op >> s;
        insert(op, s);
        cout << t[0].ans << '\n';
    }
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
