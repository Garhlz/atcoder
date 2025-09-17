#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[N];
void solve() {
    int n;
    string s;
    // 似乎要高精度
    cin >> n >> s;
    s = '0' + s;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] - '0') * i;
    }
    for (int i = n; i >= 0; i--) {
        a[i - 1] += a[i] / 10;
        a[i] %= 10;
    }
    for (int i = 0; i <= n; i++) {
        if (i == 0 && a[i] == 0) continue;
        cout << a[i];
    }
    cout << '\n';
}
/*
    1 2 3 4
个  1 2 3 4
十  1 2 3 0
百  1 2 0
千  1 0 0
*/
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
