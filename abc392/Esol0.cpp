#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[200010];
vector<pair<int, int>> ver; // 记录重边自环

int find(int x)
{
    if (x == fa[x])
        return fa[x] = x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    cin >> n >> m;
    int c[200010] = {0}, a[200010] = {0};
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (fa[find(x)] == find(y))
        { // 记录是否有多余边
            c[i] = 1, a[i] = x;
        }
        else
        {
            fa[find(x)] = find(y);
        }
    }
    int cnt = 0;
    vector<int> group;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            cnt++;
            group.push_back(i);
        }
    }
    cout << cnt - 1 << endl;
    int i, k;
    for (k = i = 1; i <= m; i++)
    {
        if (!c[i])
            continue; // 不是多余边
        while (k <= n && find(k) == find(a[i]))
            k++;
        if (k > n)
            break;
        fa[find(k)] = find(a[i]);
        printf("%d %d %d\n", i, a[i], k);
    }
}