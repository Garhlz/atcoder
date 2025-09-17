#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7 + 10;

map<int, int> vis;
vector<int> prime;
bool p[N];

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

void init(int n) {
    int t = (int)sqrt(n) + 1;
    n = t;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) prime.push_back(i);
        for (int x : prime) {
            if (i * x > n) break;
            p[i * x] = 1;
            if (i % x == 0) break;
        }
    }
}

// x == a^8 || x == (a*b)^2

void solve() {
    int x;
    cin >> x;

    init(x);

    int ans = 0;

    for (int i = 0; prime[i] * prime[i] <= x && i < prime.size(); i++) {
        for (int j = 0; prime[i] * prime[j] * prime[i] * prime[j] <= x && j < prime.size(); j++) {
            if (i != j && !vis[prime[i] * prime[j]]) {
                ans++;
                vis[prime[i] * prime[j]] = 1;
            }
        }
    }

    for (int i = 0; qpow(prime[i], 8) <= x && i < prime.size(); i++) {
        ans++;
    }

    cout << ans << '\n';
}

signed main() {
    solve();
    return 0;
}
