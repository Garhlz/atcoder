#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int dis, dis2, ans, son, f;
    Node() { dis = dis2 = ans = son = 0; }
    void show() { cout << "dis: " << dis << " dis2: " << dis2 << " ans: " << ans << " son: " << son; }
};

// 预处理出深度和最长到叶子结点的长度
void dfs1(int x, int f, vector<vector<int>> &v, vector<Node> &node) {
    node[x].f = f;

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
    dfs1(1, 0, v1, node1);
    dfs2(1, 0, v1, node1, 0);

    dfs1(1, 0, v2, node2);
    dfs2(1, 0, v2, node2, 0);

    vector<int> max_dis1(n1 + 1), max_dis2(n2 + 1);
    for (int i = 1; i <= n1; i++) {
        max_dis1[i] = node1[i].ans;
    }
    for (int i = 1; i <= n2; i++) {
        max_dis2[i] = node2[i].ans;
    }

    sort(max_dis1.begin() + 1, max_dis1.end());
    sort(max_dis2.begin() + 1, max_dis2.end(), greater<int>());

    vector<int> pre(n1 + 1);
    max_dis1[0] = 0;
    for (int i = 1; i <= n1; i++) {
        pre[i] = pre[i - 1] + max_dis1[i];
    }

    int cursor_1 = 0;
    int dia_max = max(max_dis1[n1], max_dis2[1]);
    int ans = 0;

    for (int i = 1; i <= n2; i++) {
        while (max_dis1[cursor_1] + max_dis2[i] + 1 <= dia_max && cursor_1 <= n1) {
            cursor_1++;
        }
        if (cursor_1 == 0)
            ans += n1 * (max_dis2[i] + 1) + pre[n1];
        else
            ans += (cursor_1 - 1) * dia_max + (n1 - cursor_1 + 1) * (max_dis2[i] + 1) + pre[n1] - pre[cursor_1 - 1];
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