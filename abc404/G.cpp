#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> l(m), r(m), s(m);
    for (long long i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> s[i];
    }

    vector<array<long long, 3>> eg;
    for (long long i = 1; i <= n; i++) {
        eg.push_back({i, i - 1, -1});
    }
    for (long long i = 0; i < m; i++) {
        eg.push_back({r[i], l[i] - 1, -s[i]});
        eg.push_back({l[i] - 1, r[i], s[i]});
    }

    // for(auto &nx : eg){
    //   cout << nx[0] << " -> " << nx[1] << " : " << nx[2] << "\n";
    // }

    vector<long long> d(n + 1, 8e18);
    d[n] = 0;
    bool upd;
    for (long long tr = 0; tr < 2 * (n + m) + 5; tr++) {
        upd = false;
        for (auto &nx : eg) {
            long long nd = d[nx[0]] + nx[2];
            if (d[nx[1]] > nd) {
                d[nx[1]] = nd;
                upd = true;
            }
        }
    }

    if (upd) {
        cout << "-1\n";
        return 0;
    }
    cout << -d[0] << "\n";
    return 0;
}
