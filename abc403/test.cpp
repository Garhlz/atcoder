#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int num[4] = {1111, 111, 11, 1};
string num1[4] = {"1111", "111", "11", "1"};
int present(int x) {  // 纯加法表示一个数字的长度
    int ret = 0;
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int flag1 = 0;
        if (flag && x >= num[i]) ret++;
        while (x >= num[i]) {
            if (flag1) ret++;  // 加号
            flag1 = 1;
            x -= num[i];
            ret += 4 - i;
        }
        if (flag1) flag++;
    }
    return ret;
}
string gene(int x) {
    string ret = "";
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int flag1 = 0;
        if (flag && x >= num[i]) ret += '+';
        while (x >= num[i]) {
            if (flag1) ret += '+';  // 加号
            flag1 = 1;
            x -= num[i];
            ret += num1[i];
        }
        if (flag1) flag++;
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    int len = present(n);
    cout << "len: " << len << endl;
    cout << gene(n);
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