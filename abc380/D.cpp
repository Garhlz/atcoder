#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
string s;
int len;
char func(int pos) {
    int mx = (int)log2(pos / len);
    int t = 0;
    // 不对, 这里是最多的倍数次数
    for (int i = mx; i >= 0; i--) {
        if (pos <= len) break;
        if (pos > (len << i)) {  // 不可以等于
            pos -= (len << i);
            t++;
        }
    }
    if (t & 1)
        t = 1;
    else
        t = 0;
    char ret = s[pos - 1];
    if (t) {
        if (ret >= 'a' && ret <= 'z') {
            ret = ret - 'a' + 'A';
        } else {
            ret = ret - 'A' + 'a';
        }
    }
    return ret;
}

/*
4 5
4*2 - 5 = 3

qWeRtYuIoP
8
1 1 2 3 5 8 13 21
*/
void solve() {
    cin >> s;
    len = s.size();
    int q;
    cin >> q;
    while (q--) {
        int pos;
        cin >> pos;
        cout << func(pos) << ' ';
    }
}
/*
aB
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

abcd
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
abcdABCDABCDabcdABCD

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
