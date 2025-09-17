#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()

int qpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int x = b;
    int ret = 1;
    while (x) {
        if (x & 1) ret *= a;
        a *= a;
        x >>= 1;
    }
    return ret;
}

int func(int x) {
    if (x < 10) return 0;  // 个位不算数,因为这个wa了
    int ans = 0;
    int tmp = x;
    vector<int> t;
    while (tmp) {
        t.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(all(t));
    int dig = t.size(), hi = t[0];

    for (int i = 2; i < dig; i++) {  // i表示位数,j是最高位
        for (int j = 1; j <= 9; j++) {
            ans += qpow(j, i - 1);
        }
    }

    for (int i = 1; i < hi; i++) {  // 位数相同,最高位不同
        ans += qpow(i, dig - 1);
    }

    /*
    关键在于分类讨论,从0 - a[i]-1,然后固定i讨论
    98765
    01234

    */
    for (int i = 1; i < dig; i++) {
        for (int j = 0; j < min(hi, t[i]); j++) {
            ans += qpow(hi, dig - 1 - i);  // 后续的可以直接枚举
        }
        if (i == dig - 1 && t[i] < hi) ans++;  // 是否可以取到这个数字本身
        if (t[i] >= hi) break;                 // 已经不能固定这一位然后讨论之后的了,直接结束
    }
    return ans;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int ans = func(r) - func(l - 1);  // 然后特判一下.看l是否可取(如果可取,刚才减掉了)
    cout << ans << '\n';
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
