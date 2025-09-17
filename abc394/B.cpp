#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s)
        cin >> i;
    sort(s.begin(), s.end(), [&](string a, string b)
         { return a.size() < b.size(); });
    string ans = "";
    for (auto a : s)
    {
        ans += a;
    }
    cout << ans << '\n';
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
/*
3
tc
oder
a
*/