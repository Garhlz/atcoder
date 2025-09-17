#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e6 + 10;
const int MOD = 998244353;

int fac[N], inv[N];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[n] = qpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int C(int a, int b) { return fac[a] * inv[b] % MOD * inv[a - b] % MOD; }

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a + b + c + d;
    init(n);
    int ans = 0;
    for (int i = a; i <= min(a + b, n - c + 1); i++) {
        ans = (ans + (C(i - 1, a - 1) * C(n - i, c) % MOD)) % MOD;
    }
    cout << ans << '\n';
}
/*
834150 21994 467364 994225
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
