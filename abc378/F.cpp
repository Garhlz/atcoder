#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
vector<int> v[N];
vector<int> cnt;
int flag, ans;
// 子树包括了完整的数量, 以及连续3+2的不完整链条
// 完整数量直接加到ans中, 不完整链条需要返回
// 如果当前是3, 返回不完整链条数量; 如果是2, 只能作为结束点, 无所谓
int dfs(int x, int f) {
    int cnt2 = 0, cnt3 = 0;
    vector<int> son;  // 表示有效的儿子数量
    for (int y : v[x]) {
        if (y == f) continue;
        if (cnt[y] == 2) {
            dfs(y, x);
            cnt2++;
            son.emplace_back(1);
        } else if (cnt[y] == 3) {
            int tmp = dfs(y, x);
            cnt3 += tmp;
            son.emplace_back(tmp);
        }
    }
    if (cnt[x] == 2) {
        ans += cnt3;
        return 1;
    } else if (cnt[x] == 3) {
        if (son.size() > 1) {
            int nn = son.size();
            for (int i = 0; i < nn; i++) {
                for (int j = i + 1; j < nn; j++) {
                    ans += son[i] * son[j];
                }
            }
        }
        return cnt2 + cnt3;
    } else
        return 0;
}
/*

15
1 15
11 14
2 10
1 7
9 8
6 9
4 12
14 5
4 9
8 11
7 4
1 13
3 6
11 10
*/
void solve() {
    int n;
    cin >> n;
    cnt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    dfs(1, 0);
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
