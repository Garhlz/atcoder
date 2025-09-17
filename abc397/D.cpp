#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

/*
x + y = a, x - y = b;
b * (3 * a * a + b * b) == 4 * n
其实是立方差公式的变形，获得一个因数b
*/
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i * i * i <= 4 * n; i++) {
        if ((4 * n) % i == 0) {
            int b = i;
            int x = 4 * n / b;
            int t = x - (b * b);
            if (t % 3) continue;
            t /= 3;
            int a = sqrt(t);
            if (a * a == t) {
                int p = (a + b) / 2, q = (a - b) / 2;
                if (p == 0 || q == 0) continue;
                cout << p << ' ' << q << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
