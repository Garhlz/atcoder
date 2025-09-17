#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '|') {
            int now = 0;
            i++;
            while (s[i] == '-') {
                i++;
                now++;
            }
            ans.push_back(now);
            i--;
        }
    }
    for (auto x : ans) {
        cout << x << ' ';
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
