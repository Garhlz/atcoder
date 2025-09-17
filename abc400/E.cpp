#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;

int is_prime[N];
int p[N];
int dp[N];
int factor_num[N];
vector<int> prime;

void Euler() {  // 就是在线性筛的同时记录最小质因子
    is_prime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!is_prime[i]) {
            prime.push_back(i);
            p[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < N; j++) {
            is_prime[i * prime[j]] = 1;
            // i是倍数, prime[j]是质数, 标记i * prime[j]是合数,最小质因数是prime[j]
            p[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
            // 之后再标记, 就有更小的质因数了, 也就是i中包含的prime[j]这个数字
        }
    }
}

void init() {
    factor_num[1] = 0;
    for (int i = 2; i < N; i++) {
        int k = i / p[i];  // 当前最小质因子, 从之前的序列中转移即可
        if (k % p[i] == 0)
            factor_num[i] = factor_num[k];  // 说明当前质因子是重复的
        else
            factor_num[i] = factor_num[k] + 1;  // 当前质因子是新的

        if (factor_num[i] == 2) {
            dp[i] = i * i;  // 当前数字本身满足条件, 平方之后就是要求的数字
        } else {
            dp[i] = dp[i - 1];  // 继承
        }
    }
}

void solve() {
    Euler();
    init();
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x = (int)sqrt(x);
        cout << dp[x] << "\n";
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
