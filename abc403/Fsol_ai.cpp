#include <bits/stdc++.h>
using namespace std;

const int N = 2002;

vector<pair<string, bool>> sum(N);

pair<string, bool> solve(int x) {
    if (x == 1) return {"1", false};
    if (x == 11) return {"11", false};
    if (x == 111) return {"111", false};
    if (x == 1111) return {"1111", false};
    if (!sum[x].first.empty()) return sum[x];

    string best_s;
    bool is_sum = false;
    int min_len = INT_MAX;

    // 乘法分解
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            auto [s1, sum1] = solve(i);
            auto [s2, sum2] = solve(x / i);
            if (sum1) s1 = "(" + s1 + ")";
            if (sum2) s2 = "(" + s2 + ")";
            int len = s1.size() + 1 + s2.size();
            if (len < min_len) {
                min_len = len;
                best_s = s1 + "*" + s2;
                is_sum = false;
            }
        }
    }

    // 加法分解
    for (int i = 1; i <= x / 2; ++i) {
        auto [s1, sum1] = solve(i);
        auto [s2, sum2] = solve(x - i);
        int len = s1.size() + 1 + s2.size();
        if (len < min_len) {
            min_len = len;
            best_s = s1 + "+" + s2;
            is_sum = true;
        }
    }

    return sum[x] = {best_s, is_sum};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n).first << '\n';
    return 0;
}