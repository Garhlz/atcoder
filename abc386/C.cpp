#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void solve() {
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    if (s.size() == t.size()) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) cnt++;
        }
        if (cnt <= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else if (s.size() == t.size() - 1) {
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i])
                continue;
            else if (s[i] == t[i + 1] && flag == 0) {
                flag = 1;
                t = t.substr(0, i) + t.substr(i + 1);
            } else {
                flag = 2;
                break;
            }
        }
        if (s == t.substr(1)) flag = 1;
        if (flag == 1 || flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else if (s.size() == t.size() + 1) {
        swap(s, t);
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i])
                continue;
            else if (s[i] == t[i + 1] && flag == 0) {
                flag = 1;
                t = t.substr(0, i) + t.substr(i + 1);
            } else {
                flag = 2;
                break;
            }
        }
        if (s == t.substr(1)) flag = 1;
        if (flag == 1 || flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else
        cout << "No\n";
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
