#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[9], b[9];
void solve() {
    vector<string> v(9);
    for (int i = 1; i <= 8; i++) {
        string s;
        cin >> s;
        s = ' ' + s;
        v[i] = s;
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (v[i][j] == '#') {
                a[i] = 1;
                b[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 8; i++) {
        if (a[i]) continue;
        for (int j = 1; j <= 8; j++) {
            if (b[j]) continue;
            ans++;
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
