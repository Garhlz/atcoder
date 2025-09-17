#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
/*
因为每个'/'两边的1和2只会被遍历到最多一次, 遇到相邻的/就会停止, 所以这种方法也是on的
*/
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != '/') continue;
        int x = i - 1, y = i + 1;
        int now = 1;
        while (x >= 0 && y < n && s[x] == '1' && s[y] == '2') {
            now += 2;
            x--;
            y++;
        }
        ans = max(ans, now);
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
/*
22
/1211/2///2111/2222/11
*/
