#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct Seg {
    int l, r, color;
} seg[N];
// 直接用结构体维护好了
int fa[N], color_cnt[N];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        seg[i] = {i, i, i};  // 闭区间
        fa[i] = i;
        color_cnt[i] = 1;
    }
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            int f = find(x);
            color_cnt[seg[f].color] -= (seg[f].r - seg[f].l + 1);
            seg[f].color = y;
            color_cnt[seg[f].color] += (seg[f].r - seg[f].l + 1);
            if (seg[f].l - 1 > 0) {
                int fl = find(seg[f].l - 1);
                if (seg[fl].color == y) {
                    fa[fl] = f;
                    seg[fl].color = 0;
                    seg[f].l = seg[fl].l;
                }
            }
            if (seg[f].r + 1 <= n) {
                int fr = find(seg[f].r + 1);
                if (seg[fr].color == y) {
                    fa[fr] = f;
                    seg[fr].color = 0;
                    seg[f].r = seg[fr].r;
                }
            }
        } else {
            cin >> x;
            cout << color_cnt[x] << '\n';
        }
    }
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
/*
5 6
1 5 4
1 4 2
2 2
1 3 2
1 2 3
2 3

*/