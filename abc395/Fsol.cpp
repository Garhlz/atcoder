#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, x;
ll u[N], d[N];

bool check(ll H) {
    // 初始化第一颗牙的范围
    ll L = max(0LL, H - d[1]);  // 左端：确保 D_1' >= 0
    ll R = min(u[1], H);        // 右端：U_1' <= u[1] 且 <= H
    if (L > R) return false;    // 如果范围无效，直接返回 false

    // 逐个检查后续牙齿
    for (int i = 2; i <= n; i++) {
        ll curL = max(0LL, H - d[i]);  // 当前牙的自身左端
        ll curR = min(u[i], H);        // 当前牙的自身右端
        // 更新范围：交集当前范围和前一牙的扩展范围 [L-x, R+x]
        ll newL = max(curL, L - x);    // 左端取较大值
        ll newR = min(curR, R + x);    // 右端取较小值
        if (newL > newR) return false; // 如果范围无效，返回 false
        L = newL;                      // 更新为当前范围
        R = newR;
    }
    return true;  // 所有牙齿都满足条件
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> u[i] >> d[i];
        sum += u[i] + d[i];  // 计算总和
    }
    ll maxn = LLONG_MAX;  // 初始化上界
    for (int i = 1; i <= n; i++) {
        maxn = min(maxn, u[i] + d[i]);  // 找到最小和作为上界
    }
    ll l = 0, r = maxn, anss = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            anss = mid;  // 找到可行解，尝试更大的 H
            l = mid + 1;
        } else {
            r = mid - 1;  // 不可行，尝试更小的 H
        }
    }
    cout << sum - n * anss << endl;  // 输出最小成本
    return 0;
}