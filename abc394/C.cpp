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
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'W' && s[i + 1] == 'A')
        {
            s[i] = 'A';
            s[i + 1] = 'C';
            while (s[i - 1] == 'W')
            {
                s[i - 1] = 'A';
                s[i] = 'C';
                i--;
            }
        }
    }
    cout << s << '\n';
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
