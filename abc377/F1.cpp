#include <bits/stdc++.h>
using namespace std;

// Point and Line structures (as defined, but double for coordinates in Point
// is NOT ideal for grid problems. Consider using long long for scaled coordinates or std::pair<int, int>)
// For this explanation, let's assume Point is used for mathematical points,
// but for grid coordinates, we'll use int.

// --- 假设 Point 结构体用于数学点，但在实际棋盘格点存储时，我们将使用整数 ---
struct Point {
    double x, y;
    Point(double a, double b) : x(a), y(b) {}
    Point() : x(-1.0), y(-1.0) {}  // Use -1.0 as an invalid marker for doubles
    // For comparing floating point points in a set, this is very tricky and prone to errors.
    // If you plan to use set<Point>, convert to integer coordinates first, or define strict epsilon-based comparison.
    // For now, let's keep it as is, but be aware of the pitfalls.
    bool operator==(const Point& other) const {
        return (std::fabs(x - other.x) < 1e-9 && std::fabs(y - other.y) < 1e-9);
    }
    bool operator<(const Point& o) const {  // For std::set
        if (std::fabs(x - o.x) > 1e-9) return x < o.x;
        return y < o.y - 1e-9;  // Using epsilon for comparison
    }
};

struct Line {
    double A, B, C;
    Line(double a, double b, double c) : A(a), B(b), C(c) {}
    // This constructor is good for converting two points to general form.
    Line(Point p1, Point p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -A * p1.x - B * p1.y;
    }
    // Consider adding a constructor from specific types if you want to reuse 'Line' objects:
    // static Line createHorizontal(int r) { return Line(0.0, 1.0, -r); } // y = r
    // static Line createVertical(int c) { return Line(1.0, 0.0, -c); }   // x = c
    // static Line createSumDiagonal(int k) { return Line(1.0, 1.0, -k); } // x+y = k
    // static Line createDiffDiagonal(int k) { return Line(1.0, -1.0, -k); } // x-y = k
};

// Assuming N is long long based on your #define
#define int \
    long long  // This is a common competitive programming trick
               // But remember to use 1LL or cast for large integer literals
               // if N can be > 2*10^9

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> attacked_rows;
    std::set<int> attacked_cols;
    std::set<int> attacked_sum_diagonals;         // Stores K = i+j values
    std::set<int> attacked_diff_diagonals;        // Stores K = i-j values
    std::set<std::pair<int, int>> placed_pieces;  // To store initial chess piece positions

    for (int k = 0; k < m; ++k) {
        int r, c;  // row, column (1-indexed)
        std::cin >> r >> c;
        placed_pieces.insert({r, c});

        attacked_rows.insert(r);
        attacked_cols.insert(c);
        attacked_sum_diagonals.insert(r + c);
        attacked_diff_diagonals.insert(r - c);
    }

    // Now, calculate the total number of attacked unique squares using Inclusion-Exclusion Principle.
    // This is the tricky part. For M=1000, M^2 is large for iterating all intersections,
    // but the sets of unique attacked rows/cols/diagonals are small (at most 2M each).

    long long total_attacked_squares = 0;

    // --- Term 1: Sum of sizes of individual sets (|R| + |C| + |S| + |D|) ---
    // |R|: Each attacked row attacks N squares
    total_attacked_squares += (long long)attacked_rows.size() * n;

    // |C|: Each attacked column attacks N squares
    total_attacked_squares += (long long)attacked_cols.size() * n;

    // |S|: Sum of lengths of attacked i+j diagonals
    for (int k_sum : attacked_sum_diagonals) {
        long long count = std::min((long long)n, k_sum - 1) - std::max(1LL, k_sum - n) + 1;
        total_attacked_squares += count;
    }

    // |D|: Sum of lengths of attacked i-j diagonals
    for (int k_diff : attacked_diff_diagonals) {
        long long count = n - std::abs(k_diff);
        total_attacked_squares += count;
    }

    // --- Term 2: Subtract sizes of pairwise intersections ---
    // |R intersect C|: Rows and Columns intersection
    // Each intersection (r,c) is counted.
    total_attacked_squares -= (long long)attacked_rows.size() * attacked_cols.size();

    // |R intersect S|: Rows and Sum-Diagonals intersection
    // For each attacked row 'r' and each attacked sum_diagonal 'k_s = i+j':
    // If r + c = k_s => c = k_s - r. If 1 <= c <= n, then (r,c) is an intersection.
    long long rs_intersections = 0;
    for (int r : attacked_rows) {
        for (int k_s : attacked_sum_diagonals) {
            int c_val = k_s - r;
            if (c_val >= 1 && c_val <= n) {
                rs_intersections++;
            }
        }
    }
    total_attacked_squares -= rs_intersections;

    // |R intersect D|: Rows and Diff-Diagonals intersection
    // For each attacked row 'r' and each attacked diff_diagonal 'k_d = i-j':
    // If r - c = k_d => c = r - k_d. If 1 <= c <= n, then (r,c) is an intersection.
    long long rd_intersections = 0;
    for (int r : attacked_rows) {
        for (int k_d : attacked_diff_diagonals) {
            int c_val = r - k_d;
            if (c_val >= 1 && c_val <= n) {
                rd_intersections++;
            }
        }
    }
    total_attacked_squares -= rd_intersections;

    // |C intersect S|: Columns and Sum-Diagonals intersection
    // For each attacked col 'c' and each attacked sum_diagonal 'k_s = i+j':
    // If r + c = k_s => r = k_s - c. If 1 <= r <= n, then (r,c) is an intersection.
    long long cs_intersections = 0;
    for (int c : attacked_cols) {
        for (int k_s : attacked_sum_diagonals) {
            int r_val = k_s - c;
            if (r_val >= 1 && r_val <= n) {
                cs_intersections++;
            }
        }
    }
    total_attacked_squares -= cs_intersections;

    // |C intersect D|: Columns and Diff-Diagonals intersection
    // For each attacked col 'c' and each attacked diff_diagonal 'k_d = i-j':
    // If r - c = k_d => r = k_d + c. If 1 <= r <= n, then (r,c) is an intersection.
    long long cd_intersections = 0;
    for (int c : attacked_cols) {
        for (int k_d : attacked_diff_diagonals) {
            int r_val = k_d + c;
            if (r_val >= 1 && r_val <= n) {
                cd_intersections++;
            }
        }
    }
    total_attacked_squares -= cd_intersections;

    // |S intersect D|: Sum-Diagonals and Diff-Diagonals intersection
    // For each k_s=i+j and k_d=i-j:
    // i = (k_s + k_d) / 2
    // j = (k_s - k_d) / 2
    // Check if (k_s + k_d) and (k_s - k_d) are both even (meaning k_s and k_d have same parity)
    // and if 1 <= i,j <= n.
    long long sd_intersections = 0;
    for (int k_s : attacked_sum_diagonals) {
        for (int k_d : attacked_diff_diagonals) {
            if ((k_s + k_d) % 2 == 0) {  // Check parity
                int r_val = (k_s + k_d) / 2;
                int c_val = (k_s - k_d) / 2;
                if (r_val >= 1 && r_val <= n && c_val >= 1 && c_val <= n) {
                    sd_intersections++;
                }
            }
        }
    }
    total_attacked_squares -= sd_intersections;

    // --- Term 3: Add sizes of three-way intersections ---
    // This is where it gets verbose. You need to calculate intersections of:
    // R C S, R C D, R S D, C S D
    // Example: |R intersect C intersect S|
    // For each (r,c) in R intersect C (which is just (r,c) if both r and c are attacked):
    // Check if r+c is in attacked_sum_diagonals.
    long long rcs_intersections = 0;
    for (int r : attacked_rows) {
        for (int c : attacked_cols) {
            if (attacked_sum_diagonals.count(r + c)) {
                rcs_intersections++;
            }
        }
    }
    total_attacked_squares += rcs_intersections;

    long long rcd_intersections = 0;
    for (int r : attacked_rows) {
        for (int c : attacked_cols) {
            if (attacked_diff_diagonals.count(r - c)) {
                rcd_intersections++;
            }
        }
    }
    total_attacked_squares += rcd_intersections;

    long long rsd_intersections = 0;
    for (int r : attacked_rows) {                      // rows
        for (int k_s : attacked_sum_diagonals) {       // sum-diagonals
            for (int k_d : attacked_diff_diagonals) {  // diff-diagonals
                if ((k_s + k_d) % 2 == 0) {
                    int c_cand = (k_s - k_d) / 2;
                    // Check if this point (r, c_cand) is valid and satisfies all conditions
                    if (r >= 1 && r <= n && c_cand >= 1 && c_cand <= n && r == (k_s + k_d) / 2) {
                        rsd_intersections++;
                    }
                }
            }
        }
    }
    total_attacked_squares += rsd_intersections;

    long long csd_intersections = 0;
    for (int c : attacked_cols) {                      // cols
        for (int k_s : attacked_sum_diagonals) {       // sum-diagonals
            for (int k_d : attacked_diff_diagonals) {  // diff-diagonals
                if ((k_s + k_d) % 2 == 0) {
                    int r_cand = (k_s + k_d) / 2;
                    // Check if this point (r_cand, c) is valid and satisfies all conditions
                    if (r_cand >= 1 && r_cand <= n && c >= 1 && c <= n && c == (k_s - k_d) / 2) {
                        csd_intersections++;
                    }
                }
            }
        }
    }
    total_attacked_squares += csd_intersections;

    // --- Term 4: Subtract size of four-way intersection ---
    // |R intersect C intersect S intersect D|
    // Check if (r,c) is in attacked_rows, attacked_cols, AND r+c in attacked_sum_diagonals, AND r-c in
    // attacked_diff_diagonals.
    long long rcsd_intersections = 0;
    for (int r : attacked_rows) {
        for (int c : attacked_cols) {
            if (attacked_sum_diagonals.count(r + c) && attacked_diff_diagonals.count(r - c)) {
                rcsd_intersections++;
            }
        }
    }
    total_attacked_squares -= rcsd_intersections;

    // The number of squares that can be safely placed is total squares - total attacked squares.
    // However, the placed_pieces themselves are attacked, but are not "empty squares".
    // The problem asks for placing pieces on EMPTY squares.
    // So, total_attacked_squares will count the 'M' placed pieces as attacked.
    // The problem is asking for (N*N - number_of_attacked_unique_empty_squares - M_placed_pieces).
    // Or equivalently, N*N - (number_of_attacked_unique_squares_including_pieces).
    // The calculation above for total_attacked_squares counts all unique attacked cells.
    // So, the final answer is (N*N - total_attacked_squares).

    std::cout << (n * n - total_attacked_squares) << '\n';
}

// You still need your main function and necessary includes.
// The Point and Line structs for connect are mostly for the old approach.
// The new approach heavily relies on sets of integers for coordinates/diagonal values.

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
