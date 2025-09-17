#include <bits/stdc++.h>
#define N 1000006
#define int long long
using namespace std;

vector<int> prime;                // 存储素数
vector<int> p(N);                 // p[i] 表示i的最小质因子
vector<int> cnt(N);               // cnt[i] 表示i的不同质因子数量
vector<int> rec(N);               // rec[i] 记录平方基数为i时的最大答案
vector<bool> is_prime(N, false);  // 筛法标记数组

// 预处理最小质因子和质因子数量
void preprocess() {
    is_prime[1] = true;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i]) {
            prime.push_back(i);
            p[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < N; ++j) {
            is_prime[i * prime[j]] = true;
            p[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }

    cnt[1] = 0;
    for (int i = 2; i < N; ++i) {
        int prev = i / p[i];
        // 若prev中不含当前质因子，则数量+1
        cnt[i] = cnt[prev] + (prev % p[i] != 0);
        // 维护前缀最大值
        rec[i] = (cnt[i] == 2) ? i * i : rec[i - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    preprocess();

    int Q;
    cin >> Q;
    while (Q--) {
        int A;
        cin >> A;
        int sqrt_A = (int)sqrtl(A);  // 计算平方根
        cout << rec[sqrt_A] << '\n';
    }
    return 0;
}