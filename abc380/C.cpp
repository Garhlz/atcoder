#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

void out(int cnt, int x) {
    if (cnt == 0) return;
    while (cnt--) cout << x;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int flag = 0;
    if (s[0] == '1') flag = 1;
    vector<int> a[2];
    int now = flag;
    for (int i = 0; i < s.size(); i++) {
        int num = 0;
        while (s[i] - '0' == now) {
            i++;
            num++;
        }
        i--;
        a[now].push_back(num);
        now ^= 1;
    }
    a[0].push_back(0);
    a[1].push_back(0);
    // k-1个合并到k-2
    a[1][k - 2] += a[1][k - 1];
    a[1][k - 1] = 0;
    if (flag == 0) {
        a[0][k - 1] += a[0][k];
        a[0][k] = 0;
    } else {
        a[0][k - 2] += a[0][k - 1];
        a[0][k - 1] = 0;
    }
    int tt = max(a[0].size(), a[1].size());
    for (int i = 0; i < tt; i++) {
        if (flag == 0) {
            if (i < a[0].size()) out(a[0][i], 0);
            if (i < a[1].size()) out(a[1][i], 1);
        } else {
            if (i < a[1].size()) out(a[1][i], 1);
            if (i < a[0].size()) out(a[0][i], 0);
        }
    }
    cout << '\n';
}
/*
00110011001100 k,k+1合并
1100110011001100 k-1,k合并

10 2
1011111111



*/
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
