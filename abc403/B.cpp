#include <bits/stdc++.h>
using namespace std;

void solve() {
    string t, u;
    cin >> t >> u;
    for (int i = 0; i < t.size(); i++) {
        int j = i, k = 0;
        while (j < t.size() && k < u.size() && (t[j] == u[k] || t[j] == '?')) {
            j++, k++;
        }
        if (k == u.size()) {
            cout << "Yes" << '\n';
            return;
        }
    }
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
