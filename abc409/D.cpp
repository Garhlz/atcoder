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
    string s;
    cin >> s;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i + 1] < s[i]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << s << '\n';
        return;
    }
    int pos1 = n;
    for (int i = pos + 1; i < n; i++) {
        if (s[i] > s[pos]) {  // 找到后续第一个比它大的地方, 插入即可
            pos1 = i;
        }
    }

    string ans = s.substr(0, pos) + s.substr(pos + 1, pos1 - 1 - pos + 1 - 1) + s[pos] + s.substr(pos1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
3
7
atcoder
1
x
5
snuke

*/
