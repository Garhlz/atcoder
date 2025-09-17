#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (s[0] == '?' && s[1] == 'o') s[0] = '.';
    if (s[n - 1] == '?' && s[n - 2] == 'o') s[n - 1] = '.';
    vector<pii> seg;
    int cnt_o = 0;
    if (s[0] == 'o') cnt_o++;
    if (s[n - 1] == 'o') cnt_o++;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '?' && (s[i - 1] == 'o' || s[i + 1] == 'o')) s[i] = '.';
        if (s[i] == 'o') cnt_o++;
    }

    if (cnt_o == k) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') s[i] = '.';
        }
        cout << s << '\n';
        return;
    }

    int rest = k - cnt_o;

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (last == -1)
                last = i;
            else {
                continue;
            }
        } else if (s[i] != '?' && last != -1) {
            seg.emplace_back(last, i - 1);
            last = -1;
        }
    }
    if (last != -1) seg.emplace_back(last, n - 1);
    int tot = 0;
    for (auto [l, r] : seg) {
        int len = r - l + 1;
        if (len & 1)
            tot += len / 2 + 1;
        else
            tot += len / 2;
    }
    // 此时全部填满, 但是偶数长度的区间依然可以任意填充
    if (tot == rest) {  // 奇数区间全部填充, 偶数区间还是问号
        for (auto [l, r] : seg) {
            int len = r - l + 1;
            if (len & 1) {
                for (int i = l; i <= r; i++) {
                    if ((i - l) % 2 == 0)
                        s[i] = 'o';
                    else
                        s[i] = '.';
                }
            }
        }
    }
    cout << s << '\n';
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
/*
12 6
???.????.???
*/
