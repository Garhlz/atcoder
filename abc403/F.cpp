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

void solve(int n) {
    // int n;
    // cin >> n;
    int x = 0, y = 1;
    int ans = present(n);
    x = n;
    for (int i = 0; i < n; i++) {
        int pre = present(i);
        for (int j = 2; j <= n - i; j++) {
            int now = pre;
            if ((n - i) % j) continue;
            int t1 = present((n - i) / j), t2 = present(j);
            now += t1 + t2 + 6;
            int k = (n - i) / j;
            if (k == 1 || k == 11 || k == 111 || k == 1111) now -= 2;
            if (j == 1 || j == 11 || j == 111 || j == 1111) now -= 2;  // 单个数字
            if (i == 0) now--;                                         // 去掉之前的加号
            if (now < ans) {
                ans = now;
                x = i;
                y = j;
            }
        }
    }

    int z = (n - x) / y;
    cout << "ans: " << ans << endl;
    string p1 = gene(x), p2 = gene(y), p3 = gene(z);
    cout << "p1: " << p1 << " p2: " << p2 << " p3: " << p3 << endl;
    int len1 = present(x), len2 = present(y), len3 = present(z);
    cout << "len1: " << len1 << " len2: " << len2 << " len3: " << len3 << endl;
    auto out = [&](int y, int z) {
        string s2 = gene(y), s3 = gene(z);
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
    string s1 = gene(x);
    if (x == 0) {
        cout << out(y, z) << '\n';
    } else if (x == n) {
        cout << s1 << '\n';
    } else {
        string ss = s1 + "+" + out(y, z);
        cout << ss << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    std::ofstream outputFile("output.txt");  // 创建一个 ofstream 对象并打开文件

    if (outputFile.is_open()) {
        std::cout.rdbuf(outputFile.rdbuf());  // 将 cout 的缓冲区重定向到文件

        std::cout << "This line will be written to output.txt" << std::endl;
        for (int i = 1; i <= 2000; i++) {
            cout << "i= " << i << endl;
            solve(i);
            cout << "\n\n";
        }

        outputFile.close();  // 关闭文件
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return 1;
    }

    return 0;
}
