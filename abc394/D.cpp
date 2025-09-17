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
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '<' && s[i] == '>'))
            {
                st.pop();
            }
            else
                st.push(s[i]);
        }
    }
    if (st.empty())
        cout << "Yes\n";
    else
        cout << "No\n";
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
