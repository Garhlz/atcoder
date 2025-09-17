#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    string s;
    cin >> s;
    int t = 0;
    for (auto c : s)
    {
        if (c == '2')
            t++;
    }
    while (t--)
        cout << 2;
    cout << '\n';
}

signed main()
{
    solve();
}
