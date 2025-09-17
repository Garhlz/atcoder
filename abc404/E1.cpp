#include <bits/stdc++.h>
using namespace std;
/*
直接把所有非0的数字位置转移到上一个非零位置即可
因为左侧非零的数字一定要转移, 因此合并到左侧就是最优方案
所有0的位置只会遍历一次, 所有非零也只会遍历一次, 因此实际上的复杂度是On
从左到右遍历方便了记录上一个位置
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> c(n), a(n);
    for (int i = 1; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    int pre = 0;
    for (int i = 1; i < n; i++) {
        if (a[i]) {
            int l = i, r = i;
            while (pre < l) {
                res++;
                int nl = l;
                for (int j = l; j <= r; j++) {
                    nl = min(nl, j - c[j]);
                }
                r = l;
                l = nl;
            }
            pre = i;
        }
    }
    cout << res << "\n";
    return 0;
}