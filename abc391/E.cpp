#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
010011101
0 1 1
1
010001101
0 0 1
0
递归进入三个部分中，计算出分别转化三个部分的消耗，取最小的2个即可
*/

int dfs1(const string &s)
{
    if (s.length() == 3)
    {
        int x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                x++;
        }
        if (x >= 2)
            return 1;
        else
            return 0;
    }
    else
    {
        int n = s.size() / 3;
        int t1 = dfs1(s.substr(0, n));
        int t2 = dfs1(s.substr(n, n));
        int t3 = dfs1(s.substr(n * 2, n));
        int now = t1 + t2 + t3;
        if (now >= 2)
            return 1;
        else
            return 0;
    }
}

int dfs2(const string &s, int t)
{ // t是转化的目标
    if (s.length() == 3)
    {
        int x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' == t)
                x++;
        }
        if (x >= 2)
            return 0;
        else
            return 2 - x;
    }
    else
    {
        int n = s.size() / 3;
        int t1 = dfs2(s.substr(0, n), t);
        int t2 = dfs2(s.substr(n, n), t);
        int t3 = dfs2(s.substr(n * 2, n), t);
        return t1 + t2 + t3 - max(t1, max(t2, t3));
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = dfs1(s);
    cout << dfs2(s, t ^ 1) << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
