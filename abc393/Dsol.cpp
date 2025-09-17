#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N >> S;
    S = ' ' + S;  // 1-based indexing
    int M = 0, cnt = 0;
    vector<int> pos;
    for (int i = 1; i <= N; i++) {
        if (S[i] == '1') {
            M++;
            pos.push_back(i);
        }
    }
    // 找到中位数位置
    int mid_idx = M / 2;  // 0-based for vector
    int mid = pos[mid_idx];  // 中位数位置
    ll ans = 0;
    cnt = 0;
    // 计算左边 1 到 mid 的距离
    for (int i = 0; i < mid_idx; i++) {
        cnt++;
        ans += mid - pos[i];
        ans -= (mid_idx + 1 - cnt);  // 调整因子
    }
    cnt = mid_idx + 1;
    // 计算右边 1 从 mid 移动的距离
    for (int i = mid_idx + 1; i < M; i++) {
        cnt++;
        ans += pos[i] - mid;
        ans -= (cnt - (mid_idx + 1));  // 调整因子
    }
    cout << ans << endl;
    return 0;
}