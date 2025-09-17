#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int dep, dis, dis2, ans, son, f;
    Node() { dep = dis = dis2 = ans = son = 0; }
    void show() {
        cout << "dep: " << dep << " dis: " << dis << " dis2: " << dis2 << " ans: " << ans << " son: " << son;
    }
};

// 预处理出深度和最长到叶子结点的长度
void dfs1(int x, int f, vector<vector<int>> &v, vector<Node> &node) {
    node[x].f = f;
    node[x].dep = node[f].dep + 1;
    for (int y : v[x]) {
        if (y == f) continue;
        dfs1(y, x, v, node);
        if (node[y].dis + 1 > node[x].dis) {
            node[x].dis2 = node[x].dis;
            node[x].dis = node[y].dis + 1;
            node[x].son = y;  // 最长的儿子
        } else if (node[y].dis + 1 > node[x].dis2) {
            node[x].dis2 = node[y].dis + 1;
        }
    }
}
// 这个函数试图直接把来自父节点的长度合并到最长,次长子链之中, 但是这个逻辑是错误的
// void func(int n, vector<Node> &node) {
//     for (int x = 1; x <= n; x++) {
//         if (node[x].dep > node[x].dis) {
//             node[x].dis2 = node[x].dis;
//             node[x].dis = node[x].dep;
//             node[x].son = node[x].f;
//         } else if (node[x].dep > node[x].dis2) {
//             node[x].dis2 = node[x].dep;
//         }
//     }
// }

// up表示来自父节点的最长长度, 总之就是来自父节点, 最长子链, 次长子链, 这三个分开考虑
void dfs2(int x, int f, vector<vector<int>> &v, vector<Node> &node, int up_from_fa) {
    int up = up_from_fa;
    node[x].ans = max(up, node[x].dis);
    for (int y : v[x]) {
        if (y == f) continue;
        int next_up;
        if (y == node[x].son) {
            next_up = max(up + 1, node[x].dis2 + 1);
        } else {
            next_up = max(up + 1, node[x].dis + 1);
        }
        dfs2(y, x, v, node, next_up);
    }
}

void solve() {
    int n1, n2;

    cin >> n1;
    vector<vector<int>> v1(n1 + 1);
    vector<Node> node1(n1 + 1);
    for (int i = 0; i < n1 - 1; i++) {
        int a, b;
        cin >> a >> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }

    cin >> n2;
    vector<vector<int>> v2(n2 + 1);
    vector<Node> node2(n2 + 1);
    for (int i = 0; i < n2 - 1; i++) {
        int a, b;
        cin >> a >> b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    node1[0].dep = -1;
    node2[0].dep = -1;
    dfs1(1, 0, v1, node1);
    dfs2(1, 0, v1, node1, 0);

    dfs1(1, 0, v2, node2);
    dfs2(1, 0, v2, node2, 0);

    auto out = [](int n, vector<Node> &a) {
        for (int i = 1; i <= n; i++) {
            cout << "i: " << i << '\n';
            a[i].show();
            cout << '\n';
        }
        cout << '\n';
    };

    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n1; i++) {
        s1 += node1[i].ans;
    }

    for (int i = 1; i <= n2; i++) {
        s2 += node2[i].ans;
    }

    // out(n1, node1);
    // out(n2, node2);

    cout << s1 * n2 + s2 * n1 + n1 * n2 << '\n';
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
/*
7
5 6
1 3
5 7
4 5
1 6
1 2
5
5 3
2 4
2 3
5 1
*/