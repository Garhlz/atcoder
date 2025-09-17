#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    string a = s;
    reverse(all(a));
    if (s == a) {
        cout << s << '\n';
        return;
    }
    a += '#' + s;
    vector<int> pi(n * 3, 0);
    auto kmp = [&](const string &s) {  // 因为逻辑是kmp不包括自身长度相等的串,所以这里出问题
        int n = (int)s.size();
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi[n - 1];  // 求出当前最长公共前后缀即可
    };

    int x = kmp(a);
    a = s;
    reverse(all(a));
    s += a.substr(x);
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
