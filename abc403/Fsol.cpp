#include <bits/stdc++.h>
using namespace std;

#define psi pair<string, int>
const int N = 2002;
vector<psi> ans(N);
psi solve(int x) {
    if (x == 1) return {"1", 0};
    if (x == 11) return {"11", 0};
    if (x == 111) return {"111", 0};
    if (x == 1111) return {"1111", 0};
    if (!ans[x].first.empty()) return ans[x];

    string best_s;
    int is_sum = 0;
    int min_len = INT_MAX;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            auto [s1, sum1] = solve(i);
            auto [s2, sum2] = solve(x / i);
            if (sum1) s1 = "(" + s1 + ")";
            if (sum2) s2 = "(" + s2 + ")";
            int len = s1.size() + 1 + s2.size();
            if (len < min_len) {
                min_len = len;
                best_s = s1 + "*" + s2;
                is_sum = 0;
            }
        }
    }

    for (int i = 1; i <= x / 2; i++) {
        auto [s1, sum1] = solve(i);
        auto [s2, sum2] = solve(x - i);
        int len = s1.size() + 1 + s2.size();
        if (len < min_len) {
            min_len = len;
            best_s = s1 + "+" + s2;
            is_sum = 1;
        }
    }

    return ans[x] = {best_s, is_sum};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << solve(n).first << '\n';
    return 0;
}