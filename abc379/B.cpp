#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') {
            int now = 0;
            while (s[i] == 'O' && i < n) {
                now++;
                i++;
            }
            mp[now]++;
            i--;
        }
    }
    int ans = 0;
    for (auto h : mp) {
        if (h.first >= k) {
            ans += (h.first / k) * h.second;
        }
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
