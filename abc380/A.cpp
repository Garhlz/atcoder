#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 6; i++) {
        int now = n % 10;
        if (now == 1)
            a++;
        else if (now == 2)
            b++;
        else if (now == 3)
            c++;
        n /= 10;
    }
    if (a == 1 && b == 2 && c == 3) {
        cout << "Yes\n";
    } else
        cout << "No\n";
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
