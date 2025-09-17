#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_VAL = 1e6 + 1; // 值域上限为 10^6 + 1
const int MAX_N = 1e5 + 10;  // N 的最大值 10^5 + 余量

int main()
{
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);        // 存储输入数组，从 1 开始
    vector<int> vis(MAX_VAL, 0); // 桶计数，记录每个值的出现次数
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[a[i]]++;
    }

    vector<ll> anss(MAX_VAL, 0);                      // 存储每个值的最大可能 GCD
    int max_a = *max_element(a.begin() + 1, a.end()); // 找到最大 A_i
    for (int x = 1; x <= max_a; x++)
    { // 枚举可能的 GCD 值至 max(A_i)
        ll sum = 0;
        for (int j = x; j <= max_a; j += x)
        { // 计算 x 的倍数个数
            sum += vis[j];
        }
        if (sum >= k)
        { // 如果个数足够，更新答案
            for (int j = x; j <= max_a; j += x)
            {
                anss[j] = max(anss[j], (ll)x);
            }
        }
    }

    // 输出每个位置的答案
    for (int i = 1; i <= n; i++)
    {
        cout << anss[a[i]] << '\n';
    }

    return 0;
}