#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < 3; i++) {
        mp[s[i]]++;
    }
    if (mp['A'] == 1 && mp['B'] == 1 && mp['C'] == 1)
        cout << "Yes\n";
    else
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
