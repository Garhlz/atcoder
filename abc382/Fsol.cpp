#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

const int MAXW = 2e5 + 10;
const int INF = 1e9;

int h, w, n;
int res[4 * MAXW];
int tag[4 * MAXW];
int ans[MAXW];

struct Bar {
    int r, c, l, id;
};

// 比较函数，用于按 r 降序排序
bool compareBars(const Bar& a, const Bar& b) { return a.r > b.r; }

// 判断区间 [al, ar] 是否完全包含在 [bl, br] 内
bool is_all_covered(int al, int ar, int bl, int br) { return (bl <= al && ar <= br); }

// 判断区间 [al, ar] 是否与 [bl, br] 无交集
bool is_none_overlap(int al, int ar, int bl, int br) { return (al > br || ar < bl); }

// 上传子节点信息更新当前节点
void pushup(int p) { res[p] = min(res[2 * p], res[2 * p + 1]); }

// 对节点 p 设置懒惰标记 x
void apply_tag(int p, int x) {
    res[p] = x;
    tag[p] = x;
}

// 下发懒惰标记
void pushdown(int p) {
    if (tag[p] != h + 1) {
        apply_tag(2 * p, tag[p]);
        apply_tag(2 * p + 1, tag[p]);
        tag[p] = h + 1;  // 重置懒惰标记为空
    }
}

// 构建线段树
void build(int p, int l, int r) {
    tag[p] = h + 1;  // 初始懒惰标记为空
    if (l == r) {
        res[p] = h;  // 初始时每个位置的高度都是 h
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}

// 区间更新：将 [ql, qr] 区间的高度设置为 x
void update(int p, int l, int r, int ql, int qr, int x) {
    if (is_all_covered(l, r, ql, qr)) {
        apply_tag(p, x);
        return;
    }
    if (!is_none_overlap(l, r, ql, qr)) {
        int mid = (l + r) / 2;
        pushdown(p);
        update(2 * p, l, mid, ql, qr, x);
        update(2 * p + 1, mid + 1, r, ql, qr, x);
        pushup(p);
    }
}

// 区间查询最小值：查询 [ql, qr] 区间的最小高度
int query(int p, int l, int r, int ql, int qr) {
    if (is_all_covered(l, r, ql, qr)) {
        return res[p];
    }
    if (!is_none_overlap(l, r, ql, qr)) {
        int mid = (l + r) / 2;
        pushdown(p);
        int left_min = query(2 * p, l, mid, ql, qr);
        int right_min = query(2 * p + 1, mid + 1, r, ql, qr);
        return min(left_min, right_min);
    }
    return h + 1;  // 不相交时返回一个比所有可能高度都大的值
}

int main() {
    cin >> h >> w >> n;

    vector<Bar> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].r >> a[i].c >> a[i].l;
        a[i].id = i;
    }

    sort(a.begin(), a.end(), compareBars);

    build(1, 1, w);  // 初始化线段树

    for (int i = 0; i < n; ++i) {
        int lps = a[i].c;
        int rps = a[i].c + a[i].l - 1;
        int hgh = query(1, 1, w, lps, rps);
        update(1, 1, w, lps, rps, hgh - 1);
        ans[a[i].id] = hgh;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}