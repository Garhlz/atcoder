#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define pii array<int, 2>
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

struct Point {
    double x, y;
    Point(double a, double b) : x(a), y(b) {}
    Point() : x(-1.0), y(-1.0) {}
    bool operator==(const Point& other) const { return (x == other.x && y == other.y); }
    bool operator<(const Point& o) const { return (x == o.x ? y < o.y : x < o.x); }
};

struct Line {
    double A, B, C;
    Line(double a, double b, double c) : A(a), B(b), C(c) {}
    Line(Point a, Point b) {
        A = b.y - a.y;
        B = a.x - b.x;
        C = -A * a.x - B * a.y;
    }
};
// Small epsilon for floating-point comparisons
const double EPSILON = 1e-9;

// Helper function to check if a double is close to zero
bool is_zero(double val) { return std::fabs(val) < EPSILON; }
Point connect(Line a, Line b, int n) {
    double det = a.A * b.B - b.A * a.B;  // 克莱姆法则的行列式

    // 情况 1：直线平行或重合
    if (is_zero(det)) {
        // 检查直线是否重合（无限个交点）。
        // 如果 (A1*C2 - A2*C1) 和 (B1*C2 - B2*C1) 也都接近零，则它们重合。
        if (is_zero(a.A * b.C - b.A * a.C) && is_zero(a.B * b.C - b.B * a.C)) {
            // 直线重合。对于此函数，我们将其视为范围内没有单个“有效”交点。
            // 如果需要处理重叠的线段，那是一个更复杂的问题，涉及到将线段投影到轴上并检查重叠。
            return Point(-1.0, -1.0);  // 范围内没有唯一的交点
        } else {
            // 直线平行且不重合，因此没有交点。
            return Point(-1.0, -1.0);
        }
    } else {
        // 情况 2：直线相交于一个唯一的点
        Point intersection_point;
        intersection_point.x = (a.B * b.C - b.B * a.C) / det;
        intersection_point.y = (b.A * a.C - a.A * b.C) / det;

        // 定义 n x n 正方形的边界
        double min_val = static_cast<double>(1);
        double max_val = static_cast<double>(n);

        // 检查交点是否在 [0,0] 到 [n,n] 范围内。
        // 我们使用 EPSILON 进行稳健的浮点数比较。
        if (intersection_point.x >= min_val - EPSILON && intersection_point.x <= max_val + EPSILON &&
            intersection_point.y >= min_val - EPSILON && intersection_point.y <= max_val + EPSILON) {
            return intersection_point;  // 交点在范围内
        } else {
            return Point(-1.0, -1.0);  // 交点在范围外
        }
    }
}

int influenced_point_number(Line l, int n) {
    if (l.A == 0 || l.B == 0) return n;
    Point up = connect(l, Line(1, 0, -1), n);
    if (up.x == -1 && up.y == -1) up = connect(l, Line(0, 1, -1), n);
    Point down = connect(l, Line(1, 0, -n), n);
    if (down.x == -1 && down.y == -1) down = connect(l, Line(0, 1, -n), n);
    return abs(up.y - down.y) + 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Line> lines;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        Point p(t1, t2);
        Line l1 = Line(p, Point(t1, t2 + 1));
        Line l2 = Line(p, Point(t1 + 1, t2));
        Line l3 = Line(p, Point(t1 + 1, t2 + 1));
        Line l4 = Line(p, Point(t1 - 1, t2 + 1));
        lines.push_back(l1);
        lines.push_back(l2);
        lines.push_back(l3);
        lines.push_back(l4);
        ans += influenced_point_number(l1, n);
        ans += influenced_point_number(l2, n);
        ans += influenced_point_number(l3, n);
        ans += influenced_point_number(l4, n);
    }
    set<Point> st;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = i + 1; j < lines.size(); j++) {
            Point now = connect(lines[i], lines[j], n);
            if (!(now.x == -1 && now.y == -1)) {
                st.insert(now);
            }
        }
    }
    ans -= st.size();
    ans = n * n - ans;
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
