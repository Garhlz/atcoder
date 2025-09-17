#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

struct Segtree
{
    vector<int> tr;

    Segtree(int n) : tr(n * 4, 0) {}

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            tr[node] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(node << 1, l, m);
        build(node << 1 | 1, m + 1, r);
        tr[node] = tr[node << 1] + tr[node << 1 | 1];
    }

    void update(int node, int l, int r, int x)
    {
        if (l == r)
        {
            tr[node]--;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m)
        {
            update(node << 1, l, m, x);
        }
        else
        {
            update(node << 1 | 1, m + 1, r, x);
        }
        tr[node] = tr[node << 1] + tr[node << 1 | 1];
    }

    int query(int node, int l, int r, int k)
    {
        if (l == r)
        {
            return l;
        }
        int m = l + r >> 1;
        if (tr[node << 1] < k)
        {
            return query(node << 1 | 1, m + 1, r, k - tr[node << 1]);
        }
        return query(node << 1, l, m, k);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
    }
    vector<int> res(n + 1);
    Segtree seg(n);
    seg.build(1, 1, n);

    for (int i = n; i >= 1; i--)
    {
        int id = seg.query(1, 1, n, pos[i]);
        res[id] = i;
        seg.update(1, 1, n, id);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}