#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
    ll sum, cnt, s0, s1;
} trie[9000002];
// 先按照lowbit排列, 如果两个数字lowbit不同, 他们和的lowbit等于其中较小的lowbit, 可以用前缀和处理
// 用字典树维护每一段相邻的lowbit相等区间, 每个结点都要记录当前的"数字的这个位是这个的"的数量和值的和, 以便计算,
// 把小区间操作降低到nlogv, v表示最大值
ll n, a[200002], ans, r, idx, now;
ll lowbit(ll x) {
    if (!x) return 114514;
    return x & (-x);
}
bool cmp(ll az, ll bz) { return lowbit(az) > lowbit(bz); }
ll s0(ll x) {
    if (!trie[x].s0) trie[x].s0 = ++idx;
    return trie[x].s0;
}
ll s1(ll x) {
    if (!trie[x].s1) trie[x].s1 = ++idx;
    return trie[x].s1;
}
ll fd(ll x, ll p, ll d) {
    if (d > 30) return 0;
    if (x & (1 << d)) return ((trie[s1(p)].sum + trie[s1(p)].cnt * now) >> d) + fd(x, s0(p), d + 1);
    return ((trie[s0(p)].sum + trie[s0(p)].cnt * now) >> d) + fd(x, s1(p), d + 1);
}
void update(ll x, ll p, ll d) {
    if (d > 30) return;
    if (d > 1) trie[p].sum += x, trie[p].cnt++;
    if (x & (1 << d))
        update(x, s1(p), d + 1);
    else
        update(x, s0(p), d + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (ll i = 1, sum1 = 0, cnt1 = 0, sum2 = 0, cnt2 = 0; i <= n; i++) {
        ans += (sum1 + cnt1 * a[i]) / lowbit(a[i]);
        cnt2++, sum2 += a[i];
        now = a[i] / lowbit(a[i]);
        update(now, r, 1);
        ans += fd(now, r, 1);
        if (lowbit(a[i]) != lowbit(a[i + 1])) cnt1 += cnt2, sum1 += sum2, cnt2 = 0, sum2 = 0, r = ++idx;
    }
    cout << ans;
}
