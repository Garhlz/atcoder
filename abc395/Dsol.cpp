#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    // 定义三个数组：
    // st[i]：巢 i 当前的坐标位置
    // ed[i]：坐标位置 i 当前对应的巢编号
    // home[i]：鸽子 i 当前所在的坐标位置
    vector<int> st(N + 1), ed(N + 1), home(N + 1);

    // 初始化：每个鸽子和巢都在初始位置
    for (int i = 1; i <= N; i++)
    {
        st[i] = i;   // 巢 i 的坐标位置为 i
        ed[i] = i;   // 坐标位置 i 的巢编号为 i
        home[i] = i; // 鸽子 i 在坐标位置 i
    }

    // 处理 Q 次操作
    for (int i = 1; i <= Q; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            // 操作 1：将鸽子 a 移动到巢 b
            int a, b;
            cin >> a >> b;
            home[a] = st[b]; // 更新鸽子 a 的坐标位置为巢 b 当前的坐标
        }
        else if (op == 2)
        {
            // 操作 2：交换巢 a 和巢 b 中的所有鸽子
            int a, b;
            cin >> a >> b;
            // 更新坐标位置的巢编号
            ed[st[a]] = b; // 原先巢 a 的坐标现在对应巢 b
            ed[st[b]] = a; // 原先巢 b 的坐标现在对应巢 a
            // 交换巢 a 和巢 b 的坐标位置
            swap(st[a], st[b]);
        }
        else if (op == 3)
        {
            // 操作 3：查询鸽子 a 当前所在的巢
            int a;
            cin >> a;
            // 鸽子 a 的坐标位置是 home[a]，对应的巢编号是 ed[home[a]]
            cout << ed[home[a]] << endl;
        }
    }

    return 0;
}