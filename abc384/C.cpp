#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

void solve() {
    vector<string> names;
    for (int i = 1; i <= (1 << 5); i++) {
        string now = "";
        for (int j = 0; j < 5; j++) {
            if (i & (1 << j)) {
                char c = 'A' + j;
                now += c;
            }
        }
        names.push_back(now);
    }

    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    map<string, int> mp;
    for (const auto &s : names) {
        int now = 0;
        for (auto c : s) {
            now += a[c - 'A'];
        }
        mp[s] = now;
    }

    sort(all(names), [&](string a, string b) {
        if (mp[a] != mp[b])
            return mp[a] > mp[b];
        else
            return a < b;
    });
    for (const auto &s : names) {
        cout << s << '\n';
    }
}

signed main() {
    solve();
    return 0;
}
/*
400 500 600 700 800
*/