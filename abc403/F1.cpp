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
    if (x == 0) return "0";
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

void solve(int n, vector<int> &best, vector<string> &sb) {
    int x = n, y = 1;
    int ans = present(n);  // 全部加起来

    for (int i = 0; i < n; i++) {
        int pre = best[i];
        if (pre >= ans) continue;
        for (int j = 2; j <= n - i; j++) {
            if ((n - i) % j) continue;

            int k = (n - i) / j;
            if (k < j) break;

            int num1 = best[j], num2 = best[k];

            int now = pre + num1 + num2 + 6;
            if (j == 1 || j == 11 || j == 111 || j == 1111) now -= 2;
            if (k == 1 || k == 11 || k == 111 || k == 1111) now -= 2;

            if (i == 0) now--;  // 去掉之前的加号
            if (now < ans) {
                ans = now;
                x = i;
                y = j;
            }
        }
    }

    int z = (n - x) / y;

    auto out = [&](int y, int z) {
        string s2 = sb[y], s3 = sb[z];  // 传入的是序号
        string ret = "";

        if (y == 1 || y == 11 || y == 111 || y == 1111)
            ret += s2;
        else
            ret += "(" + s2 + ")";

        ret += "*";

        if (z == 1 || z == 11 || z == 111 || z == 1111)
            ret += s3;
        else
            ret += "(" + s3 + ")";
        return ret;
    };

    if (x == 0) {
        sb[n] = out(y, z);
        best[n] = sb[n].size();
    } else if (x == n) {
        sb[n] = gene(n);
        best[n] = sb[n].size();
    } else {
        string ss = sb[x] + "+" + out(y, z);
        sb[n] = ss;
        best[n] = sb[n].size();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    vector<int> best(T + 1);
    vector<string> sb(T + 1);
    best[0] = 0;
    sb[0] = "0";
    best[1] = 1;
    sb[1] = "1";
    for (int i = 2; i <= 7; i++) {
        best[i] = best[i - 1] + 2;
        sb[i] = sb[i - 1] + "+1";
    }

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    std::ofstream outputFile("output1.txt");  // 创建一个 ofstream 对象并打开文件

    if (outputFile.is_open()) {
        std::cout.rdbuf(outputFile.rdbuf());  // 将 cout 的缓冲区重定向到文件

        std::cout << "This line will be written to output.txt" << std::endl;

        // 文件操作
        for (int i = 8; i <= T; i++) {
            solve(i, best, sb);
        }
        for (int i = 1; i <= T; i++) {
            cout << "i: " << i << '\n';
            cout << "best: " << best[i] << '\n';
            cout << sb[i] << "\n\n";
        }

        // cout << "best: " << best[T] << '\n';
        // cout << sb[T] << '\n';

        outputFile.close();  // 关闭文件
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    return 0;
}
